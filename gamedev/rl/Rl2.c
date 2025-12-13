#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <math.h>
#include <GL/gl.h>      // Standard OpenGL headers
#include <GLFW/glfw3.h> // GLFW headers
#include <GL/glu.h>     // GLU headers (for gluLookAt, gluPerspective)

// --- 1. Vector Structure ---
typedef struct {
    double x;
    double y;
    double z;
} Vector3;

// --- 2. RigidBody Structure (our basic Ball/Cube) ---
typedef struct {
    Vector3 position;
    Vector3 velocity;
    Vector3 acceleration;
    double mass;
} RigidBody;

// Global constant for gravity
const Vector3 GRAVITY_ACCEL = { .x = 0.0, .y = -9.81, .z = 0.0 }; 

// Global RigidBody instance for the ball
RigidBody rl_ball;

// --- 3. Core Physics Update Function ---
void update_rigid_body(RigidBody *body, double delta_time) {
    // 1. Apply Forces 
    body->acceleration.x = GRAVITY_ACCEL.x;
    body->acceleration.y = GRAVITY_ACCEL.y;
    body->acceleration.z = GRAVITY_ACCEL.z;

    // 2. Integrate Velocity
    body->velocity.x += body->acceleration.x * delta_time;
    body->velocity.y += body->acceleration.y * delta_time;
    body->velocity.z += body->acceleration.z * delta_time;

    // 3. Integrate Position
    body->position.x += body->velocity.x * delta_time;
    body->position.y += body->velocity.y * delta_time;
    body->position.z += body->velocity.z * delta_time;

    // 4. Basic Ground Collision Check (Y must be >= 0)
    if (body->position.y < 0.0) {
        body->position.y = 0.0; 
        body->velocity.y = -body->velocity.y * 0.7; 
        
        body->velocity.x *= 0.95;
        body->velocity.z *= 0.95;
        
        if (fabs(body->velocity.y) < 0.5) {
             body->velocity.y = 0.0;
        }
    }
}


// --- Ball Reset Function ---
void reset_ball() {
    // Generate random initial velocity and horizontal position
    // Center the random position and velocity for visibility
    double rand_x = (rand() % 10) - 5.0;  // Random X between -5.0 and 5.0
    double rand_z = (rand() % 10) - 5.0;  // Random Z between -5.0 and 5.0
    double rand_vel_x = (rand() % 10) - 5.0; // Random Velocity X between -5.0 and 5.0
    double rand_vel_z = (rand() % 10) - 5.0; // Random Velocity Z between -5.0 and 5.0

    rl_ball = (RigidBody){
        .position = { .x = rand_x, .y = 15.0, .z = rand_z }, // Start high up (Y=15.0)
        .velocity = { .x = rand_vel_x, .y = 0.0, .z = rand_vel_z },
        .acceleration = { 0.0, 0.0, 0.0 },
        .mass = 1.0 
    };
    printf("New Ball Launched! Pos: (%.2f, 15.0, %.2f) Vel: (%.2f, 0.0, %.2f)\n", 
           rl_ball.position.x, rl_ball.position.z, rl_ball.velocity.x, rl_ball.velocity.z);
}

// --- Mouse Button Callback Function ---
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    // Left mouse button press
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        reset_ball();
    }
}


// --- OPENGL RENDERING FUNCTIONS ---

// Replacement function: Draws a simple CUBE (to bypass potential GLU issues)
void draw_cube(double size) {
    double s = size / 2.0;

    glBegin(GL_QUADS);

    // Face 1 (Front)
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-s, -s,  s); glVertex3f( s, -s,  s);
    glVertex3f( s,  s,  s); glVertex3f(-s,  s,  s);
    
    // Face 2 (Back)
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-s, -s, -s); glVertex3f(-s,  s, -s);
    glVertex3f( s,  s, -s); glVertex3f( s, -s, -s);
    
    // Face 3 (Top)
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-s,  s, -s); glVertex3f(-s,  s,  s);
    glVertex3f( s,  s,  s); glVertex3f( s,  s, -s);
    
    // Face 4 (Bottom)
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-s, -s, -s); glVertex3f( s, -s, -s);
    glVertex3f( s, -s,  s); glVertex3f(-s, -s,  s);

    // Face 5 (Right)
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f( s, -s, -s); glVertex3f( s,  s, -s);
    glVertex3f( s,  s,  s); glVertex3f( s, -s,  s);
    
    // Face 6 (Left)
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(-s, -s, -s); glVertex3f(-s, -s,  s);
    glVertex3f(-s,  s,  s); glVertex3f(-s,  s, -s);

    glEnd();
}


void setup_view(int width, int height) {
    glViewport(0, 0, width, height);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Using GLU function for perspective
    gluPerspective(70.0, (double)width / (double)height, 0.1, 100.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Using GLU function to set camera
    gluLookAt(
        0.0, 10.0, 30.0, // Camera Position (X, Y, Z)
        0.0, 0.0, 0.0,  // Target Position
        0.0, 1.0, 0.0   // Up Axis
    );
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    setup_view(width, height);
}


// --- MAIN GAME LOOP IMPLEMENTATION ---
void game_loop(GLFWwindow* window) {
    double last_time = glfwGetTime();

    while (!glfwWindowShouldClose(window)) {
        
        // 1. Calculate Delta Time
        double current_time = glfwGetTime();
        double delta_time = current_time - last_time;
        last_time = current_time;

        // 2. Process Input
        glfwPollEvents();
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, 1);
        
        // --- 3. PHYSICS UPDATE ---
        update_rigid_body(&rl_ball, delta_time);

        // 4. RENDERING
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix(); 
        
            // Draw the Ground Plane
            glColor3f(0.3f, 0.3f, 0.3f); // Dark gray color
            glBegin(GL_QUADS);
                glVertex3f(-20.0f, 0.0f, -20.0f);
                glVertex3f( 20.0f, 0.0f, -20.0f);
                glVertex3f( 20.0f, 0.0f,  20.0f);
                glVertex3f(-20.0f, 0.0f,  20.0f);
            glEnd();

            // Draw the Ball/Cube
            // Move the rendering origin to the ball's calculated position
            glTranslated(rl_ball.position.x, rl_ball.position.y, rl_ball.position.z);
            
            // Draw the cube
            draw_cube(1.0); // Draw a cube of size 1.0
            
        glPopMatrix();

        // 5. SWAP BUFFERS
        glfwSwapBuffers(window);
    }
}


// --- MAIN FUNCTION ---
int main() {
    // Initialize random seed for the reset function
    srand(time(NULL)); 

    // --- GLFW INITIALIZATION ---
    if (!glfwInit()) return -1;

    // Request an older context that supports GLU (Compatibility Profile)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    
    int screen_width = 800;
    int screen_height = 600;
    GLFWwindow* window = glfwCreateWindow(screen_width, screen_height, "Simple GLFW Physics Demo (Cube)", NULL, NULL);
    
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    // Register the mouse callback function
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    
    // Set the initial ball state
    reset_ball(); 

    // --- OPENGL SETUP ---
    glEnable(GL_DEPTH_TEST); 
    glShadeModel(GL_SMOOTH); 
    glClearColor(0.1f, 0.1f, 0.2f, 1.0f); 
    
    setup_view(screen_width, screen_height);

    // Run the game
    game_loop(window);

    // Cleanup
    glfwTerminate();
    return 0;
}