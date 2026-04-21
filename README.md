## 🏰 Stronghold: Console-Based Battle Game

**Stronghold** is a comprehensive command-line strategic simulation developed as a **2nd-semester Software Engineering project**. Built with C++ and centered on Object-Oriented Programming (OOP), the game challenges players to manage every facet of a medieval kingdom—from military training and resource acquisition to complex diplomacy and espionage.

The project demonstrates the power of OOP in managing a multi-layered system where the economy, population morale, weather, and political stability all interact dynamically to determine the fate of the realm.

---

### 🚀 Project Objective
* To master **Advanced OOP concepts** like Inheritance, Polymorphism, and Encapsulation.
* To simulate a complex ecosystem where various systems (Economic, Political, Military) are interdependent.
* To implement robust **Exception Handling** for resource management and game logic.
* To practice **File I/O** for game state persistence and score tracking.

---

### 🛠 Core OOP Concepts Used

* **Encapsulation:** Every kingdom system (Economy, Army, Bank) is encapsulated within its own class, protecting its internal state and exposing only necessary functionality.
* **Composition:** The `Kingdom` class acts as a central hub, composed of multiple `unique_ptr` objects representing specialized subsystems.
* **Template Classes:** A generic `Resource<T>` class is used to handle various types of resources (Food, Iron, etc.) with standardized adjustment logic.
* **Custom Exception Handling:** Utilizes classes like `InsufficientResourcesException` and `CorruptionException` to manage runtime errors gracefully.

---

### 📦 Project Structure
```text
Stronghold Project/
│
├── Main.cpp          # Game loop, turn management, and command menu
├── Stronghold.cpp    # Implementation of kingdom systems and game logic
├── Stronghold.h      # Class declarations, templates, and forward declarations
├── score.txt         # Persistent record of historical kingdom scores
└── README.md         # Project documentation
```

---

### 🎮 Key Gameplay Systems

| System | Purpose |
| :--- | :--- |
| **Military & Army** | Train soldiers, manage morale, and deploy spies for sabotage. |
| **Economy & Bank** | Collect taxes, manage loans, and combat market crashes or inflation. |
| **Politics** | Hold elections, elect rulers with unique styles, and handle rebellions. |
| **Blacksmith** | Upgrade facilities to produce weapons and improve training efficiency. |
| **Diplomacy** | Form/break alliances and establish secure trade routes with rivals. |
| **Weather & Events** | Dynamic seasons and random events (Plague, Drought) impact resources. |

---

### 🖋️ Authors
* Muhammad Faizan (Software Engineering Student)
* Usman Ghani (Software Engineering Student)

---

### 🖥️ Game Output Simulation
The game features a rich, color-coded CLI interface that provides real-time updates on the status of your kingdom.


> **Note:** This project is developed for academic purposes to demonstrate proficiency in C++ system design and software architecture.
