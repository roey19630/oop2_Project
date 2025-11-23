# 🎮 Brawl Stars–Style 2D Action Game

*A C++ / SFML OOP Project*

## 📌 Overview

This project is a 2D action game where the player battles enemies, collects power-ups, avoids obstacles, and survives while the map shrinks due to incoming poison.
The goal: **eliminate all enemies before your health reaches zero.**

The player has:

* A **primary weapon** that shoots balls
* A **charged special weapon** that fires a bomb
* Visibility guided by a **Flashlight Object** following the mouse
  Enemies include:
* **Small, fast enemies**
* **Big, slow enemies**

Obstacles like **trees** and **walls** block movement, while **gifts** provide boosts.
A **poison cloud** gradually reduces the playable area.

---

## 🧱 Object-Oriented Architecture

The game is built using a large modular OOP hierarchy:

### **Core Object Structure**

* **BaseObject**

  * **MovingObject**

    * PlayerObject
    * BaseEnemyObject

      * SmallFastEnemyObject
      * BigSlowEnemyObject
    * BulletObject

      * BallObject
      * BombObject
      * LaserObject
  * **StaticObject**

    * TreeObject
    * WallObject
    * BaseGiftObject

      * FreezeGiftObject
      * LifeGiftObject
      * WeaponGiftObject
    * PortalObject
    * BushObject
* **PoisonObject / CloudPoisonObject**

### **Weapons**

* BaseWeaponObject

  * PlayerWeaponObject
  * EnemyWeaponObject

### **Game States**

Managed via Controller & State Machine:

* MenuState
* InstructionsState
* PlayState
* PauseState
* WinState
* LooseState

---

## 🔄 Game Flow & Mechanics

* **Collision detection** using a structured collision-table logic
* **State machine** handling transitions between screens
* **Factory pattern** for object creation
* **Level loading** from a board file
* **Board** manages all game objects and updates

---

## 🗂 File Structure (High-Level)

Key components (from the full list in the project):

* `Controller.*` – game loop + state manager
* `Board.*` – loads levels + updates world
* `BaseObject.*` & derived classes – all game entities
* `BaseWeaponObject.*` & derived classes – weapon mechanics
* `HandlingCollision.*` – centralized collision logic
* `TextureHandler.*`, `SoundsHandler.*` – assets
* State classes: `MenuState`, `PlayState`, `PauseState`, etc.

(Full list included in the attached documentation.)

---

## 🧠 Notable Algorithms

* **Collision Detection System** (table-driven)
* **Weapon & Bullet Management**
* **Shrinking-map poison algorithm**
* **OOP role separation via inheritance & polymorphism**

---

## 🐞 Known Issues

* Level transitions are not fully functional (cannot proceed to next level).

---

## 🧩 Contributors

* Noa Agassi
* Lara Duek
* Roey Yonayov
