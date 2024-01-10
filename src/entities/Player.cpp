#include "Player.h"

Player::Player(const std::string &texture_file_path) : Character(texture_file_path)
{
    textureFilePath = texture_file_path;
    hitBox.width = TILE_WIDTH * TILE_SCALE_FACTOR;
    hitBox.height = TILE_WIDTH * TILE_SCALE_FACTOR;
}

Player::~Player()
{
    // Cleanup code here
    // Example: If Player had dynamically allocated memory or loaded textures
    // delete myPointer;
    // UnloadTexture(myTexture);

    TextureManager::RemoveTexture(textureFilePath);
}

void Player::Update(float deltaTime)
{
    // Logger::Log("Player pixelposition: " + std::to_string(pixelPosition.x) + ", " + std::to_string(pixelPosition.y) + "\n");
    // Logger::Log("Player gridposition: " + std::to_string(gridPosition.x) + ", " + std::to_string(gridPosition.y) + "\n");
    CheckHealth();
    UpdateCooldowns(deltaTime);
    Vector2 inputDirection = HandleInputs();

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

    ApplyFriction(1000.0f, deltaTime); // TODO: switch friction Adjustment literal to a global variable.
    SetPixelPosition(Vector2Add(pixelPosition, Vector2Scale(velocity, deltaTime)));
}

void Player::Draw() const
{
    DrawTextureEx(*texture, pixelPosition, 0.0f, TILE_SCALE_FACTOR, WHITE);
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
    health -= damageAmount;
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