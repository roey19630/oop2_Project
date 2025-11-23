
Brawl Stars Game
Student Information
Noa Agassi                 318907441 
Lara Duek                346599079
Roey Yonayov         211415823


General Explanation
The objective of the game is to eliminate all enemies before the player runs out of health. The player navigates a board, battles enemies, and interacts with various objects.
In this game:
* The player has a primary weapon that shoots balls and a special weapon that charges over time and shoots a bomb.
* There are two types of enemies with different behaviors:
   * Small and fast enemies.
   * Big and slow enemies.
* The game includes various obstacles such as trees and walls that block movement, as well as power-ups that enhance the player's abilities.
* The play area shrinks over time due to encroaching poison, adding an additional layer of challenge


Design
Objects and Their Responsibilities
1. BaseObject: The base class for all objects in the game.
   * MovingObject: Inherits from BaseObject, represents objects that can move.
      * PlayerObject: Represents the player character. Manages player movement, shooting, and interactions.
      * BaseEnemyObject: Base class for all enemy characters.
         * BigSlowEnemyObject: Represents a large, slow-moving enemy.
         * SmallFastEnemyObject: Represents a small, fast-moving enemy.
      * BulletObject: Base class for all bullets fired by weapons.
         * BallObject: Represents a ball bullet.
         * BombObject: Represents a bomb bullet.
         * LaserObject: Represents a laser bullet.
   * StaticObject: Inherits from BaseObject, represents objects that do not move.
      * TreeObject: Represents a tree that blocks movement.
      * WallObject: Represents a wall that blocks movement.
      * BaseGiftObject: Base class for all gifts/power-ups.
         * FreezeGiftObject: Freezes enemies temporarily.
         * LifeGiftObject: Increases player health.
         * WeaponGiftObject: Enhances player weapon.
      * PortalObject: Represents a portal for teleportation.
      * BushObject: Represents a bush that hides the player.
   * PoisonObject: Represents poison that shrinks the play area.
      * CloudPoisonObject: Manages a collection of poison objects.
2. FlashlightObject: A member of PlayerObject. Represents the area where the player can shoot. Follows the mouse cursor and is always visible on the screen.
3. BaseWeaponObject: Base class for weapons, responsible for creating and firing bullets.
   * EnemyWeaponObject: Represents weapons used by enemies.
   * PlayerWeaponObject: Represents weapons used by the player.
4. GameState: Base class for different game states, managed by Controller.
   * MenuState: Represents the main menu.
   * PauseState: Represents the pause menu.
   * PlayState: Represents the main gameplay.
   * LooseState: Represents the state when the player loses.
   * WinState: Represents the state when the player wins.
   * InstructionsState: Represents the instructions screen.
Interaction Between Objects
* PlayerObject interacts with MovingObject and StaticObject for movement and collision detection.
* BulletObject interacts with enemies and static objects to determine hits and effects.
* Board manages all objects, loading levels, and updating game states.
* GameState and Controller manage transitions between different screens and states.
* HandlingCollision handles all collision logic between different types of objects.
File List
1. CMakeLists.txt: Build configuration file for the project.
2. TextureHandler.h / TextureHandler.cpp: Manages textures.
3. SoundsHandler.h / SoundsHandler.cpp: Manages sounds.
4. Board.h / Board.cpp: Manages game board and objects.
5. Utilities.h: Utility functions and definitions.
6. Controller.h / Controller.cpp: Main game loop and state management.
7. MenuState.h / MenuState.cpp: Main menu screen.
8. PauseState.h / PauseState.cpp: Pause screen.
9. GameState.h / GameState.cpp: Main gameplay screen.
10. LooseState.h / LooseState.cpp: Lose screen.
11. WinState.h / WinState.cpp: Win screen.
12. PlayState.h / PlayState.cpp: Active gameplay state.
13. InstructionsState.h / InstructionsState.cpp: Instructions screen.
14. BaseObject.h / BaseObject.cpp: Base class for all objects.
15. MovingObject.h / MovingObject.cpp: Base class for moving objects.
16. PlayerObject.h / PlayerObject.cpp: Player character.
17. BaseEnemyObject.h / BaseEnemyObject.cpp: Base class for enemies.
18. BigSlowEnemyObject.h / BigSlowEnemyObject.cpp: Big slow enemy.
19. SmallFastEnemyObject.h / SmallFastEnemyObject.cpp: Small fast enemy.
20. BaseGiftObject.h / BaseGiftObject.cpp: Base class for gifts.
21. FreezeGiftObject.h / FreezeGiftObject.cpp: Freeze gift.
22. LifeGiftObject.h / LifeGiftObject.cpp: Health gift.
23. WeaponGiftObject.h / WeaponGiftObject.cpp: Weapon upgrade gift.
24. BaseWeaponObject.h / BaseWeaponObject.cpp: Base class for weapons.
25. EnemyWeaponObject.h / EnemyWeaponObject.cpp: Enemy weapon.
26. PlayerWeaponObject.h / PlayerWeaponObject.cpp: Player weapon.
27. BallsWeaponObject.h / BallsWeaponObject.cpp: Ball weapon.
28. BombWeaponObject.h / BombWeaponObject.cpp: Bomb weapon.
29. PoisonObject.h / PoisonObject.cpp: Poison object.
30. WallObject.h / WallObject.cpp: Wall object.
31. BushObject.h / BushObject.cpp: Bush object.
32. PortalObject.h / PortalObject.cpp: Portal object.
33. FactoryObject.h / FactoryObject.cpp: Factory for creating objects.
34. FlashlightObject.h / FlashlightObject.cpp: Flashlight object.
35. Button.h / Button.cpp: Interactive buttons.
36. CloudPoisonObject.h / CloudPoisonObject.cpp: Manages poison cloud.
37. BombObject.h / BombObject.cpp: Bomb object.
38. BallObject.h / BallObject.cpp: Ball object.
39. HandlingCollision.h / HandlingCollision.cpp: Manages collisions.
Data Structures
* Board: Stores and manages all game objects.
* Vector: Used to store collections of objects like PoisonObject in CloudPoisonObject.
Notable Algorithms
* Collision Detection: Table-based system to handle collisions between different types of objects.
* Weapon Firing: Logic for creating and managing bullets fired by PlayerObject and BaseEnemyObject.
* State Management: Handles transitions between different game states using GameState and Controller.
Known Bugs
* Can not pass to the next level.
Other Notes
* Flashlight: A member of PlayerObject. Shows the area where the player can shoot. Follows the mouse cursor and is always visible on the screen.
* Level Loading: All objects are read from a level file managed by Board.
