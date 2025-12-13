#include <stdio.h>
#include <math.h>




// --- 1. Vector Structure (for position, velocity, acceleration) ---
typedef struct {
    double x;
    double y;
    double z;
} Vector3;

// --- 2. RigidBody Structure (our basic Ball) ---
typedef struct {
    Vector3 position;
    Vector3 velocity;
    Vector3 acceleration;
    double mass;
} RigidBody;

// Global constant for gravity (9.81 m/s^2, applied downwards)
// Assuming Z is the vertical axis in our simple world
const Vector3 GRAVITY_ACCEL = { .x = 0.0, .y = 0.0, .z = -9.81 }; 



// --- 3. Core Physics Update Function ---
// This is the function that runs every frame of the game loop
void update_rigid_body(RigidBody *body, double delta_time) {
    // 1. Apply Forces to determine Acceleration
    
    // In a full game, you would calculate forces here (thrust, drag, etc.)
    // For this basic demo, we only apply gravity to the body's acceleration
    body->acceleration.x = GRAVITY_ACCEL.x;
    body->acceleration.y = GRAVITY_ACCEL.y;
    body->acceleration.z = GRAVITY_ACCEL.z;

    // 2. Integrate Velocity (Euler Integration)
    // New Velocity = Old Velocity + Acceleration * Time
    
    body->velocity.x += body->acceleration.x * delta_time;
    body->velocity.y += body->acceleration.y * delta_time;
    body->velocity.z += body->acceleration.z * delta_time;

    // 3. Integrate Position (Euler Integration)
    // New Position = Old Position + Velocity * Time
    
    body->position.x += body->velocity.x * delta_time;
    body->position.y += body->velocity.y * delta_time;
    body->position.z += body->velocity.z * delta_time;
}

// Helper function to print the state
void print_state(int step, double time, const RigidBody *body) {
    printf("--- Time Step %d (t=%.2f s) ---\n", step, time);
    printf("Pos: (%.2f, %.2f, %.2f) m\n", body->position.x, body->position.y, body->position.z);
    printf("Vel: (%.2f, %.2f, %.2f) m/s\n\n", body->velocity.x, body->velocity.y, body->velocity.z);
}

// --- Main Execution (The Simulated Game Loop) ---
int main() {
    // Initialize our "Ball"
    RigidBody rl_ball = {
        .position = { .x = 0.0, .y = 0.0, .z = 50.0 }, // Start 50m in the air
        .velocity = { .x = 10.0, .y = 0.0, .z = 0.0 }, // Initial sideways movement (10 m/s)
        .acceleration = { 0.0, 0.0, 0.0 },
        .mass = 1.0 // Mass doesn't affect acceleration due to gravity (F=ma => a=F/m)
    };

    // Game loop parameters
    double time_step = 0.016; // A typical frame time for 60 FPS (1/60th of a second)
    double total_time = 0.0;
    int max_steps = 200; // Run for 200 steps (or about 3.2 seconds)

    printf("--- Rocket League Basic Physics Demo ---\n");
    print_state(0, total_time, &rl_ball);

    for (int i = 1; i <= max_steps; i++) {
        // Run the physics update
        update_rigid_body(&rl_ball, time_step);
        
        // Update total time
        total_time += time_step;

        // Print state every 50 steps
        if (i % 50 == 0) {
            print_state(i, total_time, &rl_ball);
        }

        // Basic ground collision check (Z must be >= 0)
        if (rl_ball.position.z < 0.0) {
            rl_ball.position.z = 0.0; // Reset position to ground level
            rl_ball.velocity.z = -rl_ball.velocity.z * 0.7; // Simple bounce (0.7 is coefficient of restitution)
            
            // Dampen horizontal velocity slightly on impact
            rl_ball.velocity.x *= 0.95;
            rl_ball.velocity.y *= 0.95;

            // Stop the simulation if it's barely moving
            if (fabs(rl_ball.velocity.z) < 1.0) {
                 printf("--- Ball has settled on the ground! ---\n");
                 print_state(i, total_time, &rl_ball);
                 break;
            }
        }
    }

    return 0;
}