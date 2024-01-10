- Create a static entity
- create a kanban board for todo list
- Initializing player() without a texture produces a hard to see error.

Resource Management: Instead of loading and unloading the texture in each entity, you could use a resource manager. A resource manager is a class that handles the loading and unloading of resources like textures. Each entity would then request its texture from the resource manager. This would ensure that each texture is only loaded once, even if it's used by multiple entities.

State Management: Your Player class is using a switch statement to handle its states. This is a common approach, but it can become difficult to manage as you add more states. Consider using a state pattern, where each state is a separate class. This would make your code more modular and easier to manage.

Input Handling: Your Player class is directly handling input. This can make it difficult to manage input as your game grows. Consider using an input manager that handles all input and then informs the relevant entities of any input they need to know about.

Cleanup: You're unloading the texture in the Player destructor. This is good practice, but if you move to a resource manager, the resource manager would handle this instead.
