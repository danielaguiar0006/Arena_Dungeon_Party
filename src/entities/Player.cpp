#include "Player.h"

// TODO: Implement Player class
Player::Player()
{

    hitBox.width = 32.0f;
    hitBox.height = 32.0f;

    walkAcceleration = 2000.0f;
    runAcceleration = 4000.0f;
    dashAcceleration = 6000.0f;
    maxWalkSpeed = 200.0f;
    maxRunSpeed = 400.0f;
    baseAttackDamage = 20.0f;
    attackRange = 50.0f;
}
/*
Player::~Player()
{
    // Cleanup code here
    // Example: If Player had dynamically allocated memory or loaded textures
    // delete myPointer;
    // UnloadTexture(myTexture);
} */

void Player::Update(float deltaTime)
{
    /*     std::cout << "Player position: " << position.x << ", " << position.y << std::endl;
        std::cout << "Player velocity: " << velocity.x << ", " << velocity.y << std::endl;
        std::cout << "Player state: " << GetCurrentState(currentState) << std::endl; */
    UpdateCooldowns(deltaTime);
    Vector2 inputDirection = HandleInputs();
    std::cout << Vector2Length(inputDirection) << std::endl;

    switch (currentState) // *While in this state, do this:*
    {
        {
        case PlayerState::Idle:
        {
            if (Vector2Length(inputDirection) > 0.0f)
            {
                SetState(PlayerState::Walking);
                break;
            }
            break;
        }

        case PlayerState::Walking:
        {
            if (Vector2Length(inputDirection) == 0.0f)
            {
                SetState(PlayerState::Idle);
                break;
            }
            /*             else if (IsKeyDown(KEY_LEFT_SHIFT))
                        {
                            SetState(PlayerState::Running);
                        } */

            Vector2 targetVelocity = Vector2Scale(inputDirection, maxWalkSpeed); // Get the target velocity based on the input direction and maximum speed
            if (Vector2Length(targetVelocity) > Vector2Length(velocity))
            {
                ApplyMovement(targetVelocity, walkAcceleration, deltaTime);
            }
            break;
        }

        case PlayerState::Dashing:
        {
            if (lastDashTimeSec < dashDurationSec)
            {
                ApplyMovement(targetDashVelocity, dashAcceleration, deltaTime);
            }
            else
            {
                SetState(PlayerState::Idle); //? Should it be to Idle or Walking?
            }
            break;
        }
        // TODO: Implement the rest of the states
        default:
            break;
        }
    }

    ApplyFriction(1000.0f, deltaTime);                                  // TODO: switch friction Adjustment literal to a global variable.
    position = Vector2Add(position, Vector2Scale(velocity, deltaTime)); // Update the position based on the velocity
    UpdateHitBox();
}

void Player::Draw() const
{
    DrawRectangleRec(hitBox, GRAY);
}

std::string Player::GetCurrentState(PlayerState state) const
{
    switch (state)
    {
    case PlayerState::Idle:
        return "Idle";
    case PlayerState::Walking:
        return "Walking";
    case PlayerState::Running:
        return "Running";
    case PlayerState::Dashing:
        return "Dashing";
    case PlayerState::Attacking:
        return "Attacking";
        /*     case PlayerState::Hurt:
                return "Hurt";
            case PlayerState::Dying:
                return "Dying"; */
    default:
        return "Unknown";
    }
}

void Player::SetState(PlayerState newState)
{
    if (currentState == newState)
        return;

    /*     std::cout << "Player state changed from " << GetCurrentState(currentState) << " to " << GetCurrentState(newState) << std::endl; */
    currentState = newState;
}

void Player::UpdateCooldowns(float deltaTime)
{
    if (lastDashTimeSec > dashCooldownSec)
    {
        lastDashTimeSec = dashCooldownSec;
    }
    else
    {
        lastDashTimeSec += deltaTime;
    }
}

Vector2 Player::HandleInputs()
{
    Vector2 inputDirection = {0.0f, 0.0f};

    if (IsKeyDown(KEY_W))
        inputDirection.y -= 1.0f;
    if (IsKeyDown(KEY_S))
        inputDirection.y += 1.0f;
    if (IsKeyDown(KEY_A))
        inputDirection.x -= 1.0f;
    if (IsKeyDown(KEY_D))
        inputDirection.x += 1.0f;

    if (Vector2Length(inputDirection) > 0.0f)
    {
        inputDirection = Vector2Normalize(inputDirection);

        if (IsKeyDown(KEY_SPACE) && lastDashTimeSec >= dashCooldownSec)
        {
            Dash(inputDirection);
        }

        return inputDirection;
    }
    else
    {
        return {0.0f, 0.0f};
    }
}

void Player::Dash(Vector2 inputDirection)
{
    SetState(PlayerState::Dashing);
    lastDashTimeSec = 0.0f; // Reset the dash cooldown

    float dashVelocityMagnitude = 600.0f;
    targetDashVelocity = Vector2Scale(inputDirection, dashVelocityMagnitude); // Set the dash velocity based on the input direction and dashSpeed or dashVelocityMagnitude
}
// TODO: Imlement all of these virtual functions in the Character class

void Player::Attack(Character *target)
{
    int x = 0;
    int y = 0;
    if (x = y)
        x = 1;
}

void Player::TakeDamage(float damageAmount)
{
    int x = 0;
    int y = 0;
    if (x = y)
        x = 1;
}

void Player::Die()
{
    int x = 0;
    int y = 0;
    if (x = y)
        x = 1;
}

void Player::DropLoot()
{
    int x = 0;
    int y = 0;
    if (x = y)
        x = 1;
}