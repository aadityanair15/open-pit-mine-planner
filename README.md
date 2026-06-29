# open-pit-mine-planner
C++ extraction sequence planner using Topological Sort

OVERVIEW

This project is a C++ algorithmic engine designed to solve a complex spatial constraint problem in mining engineering. In open-pit mining, extracting deep, high-value ore requires safely removing the overlying waste rock to prevent cave-ins (maintaining a safe wall slope).

This tool models a 2D cross-section of a mine block model as a Directed Acyclic Graph (DAG) and utilizes Depth-First Search (DFS) Topological Sorting to compute the exact, chronological extraction sequence required to reach a target block while maximizing net economic profit.

FEATURES

Geospatial Dependency Mapping: Automatically translates physical 45-degree slope constraints into directed graph edges (Child -> Parent dependencies).

Algorithmic Pit Scheduling: Uses DFS-based Topological Sort to guarantee no block is scheduled for excavation before its structural prerequisites are removed.

Profitability Analysis: Dynamically tracks and calculates the total net expected value of the extraction pit, balancing the cost of waste rock removal against ore revenue.

Memory-Optimized C++: Leverages STL containers (std::unordered_map, std::list, std::stack) with safe access patterns to prevent unnecessary map-insertion overhead during deep graph traversals.

TECHNICAL ARCHITECTURE

Language: C++ (C++11 or higher recommended)

Core Algorithm: Topological Sort via Depth-First Search (DFS)

DATA STRUCTURES:

Directed Acyclic Graph (DAG) using Adjacency Lists

std::unordered_map for $O(1)$ expected time-complexity graph lookups

std::stack for reversing the post-order DFS traversal into a valid chronological sequence

Getting Started

PREREQUISITES

You will need a C++ compiler (like GCC or Clang) installed on your system.

COMPILATION AND EXECUTION

Clone this repository to your local machine:

git clone https://github.com/YOUR_USERNAME/open-pit-mine-planner.git


Navigate into the project directory:

cd open-pit-mine-planner


Compile the source code using g++:

g++ main.cpp -o MinePlanner


Run the executable:

Windows: .\MinePlanner.exe

Mac/Linux: ./MinePlanner

Example Output

When executed, the program identifies the target block and outputs the safe step-by-step extraction sequence from the surface down to the target, concluding with the total net profit.

=== SAFE EXTRACTION PIT SEQUENCE ===
Targeting Block ID: 12

Step 1: Mine Block 2 at [0][2] | Value: $-50
Step 2: Mine Block 1 at [0][1] | Value: $-50
Step 3: Mine Block 3 at [0][3] | Value: $-50
Step 4: Mine Block 7 at [1][2] | Value: $-50
...
Step 9: Mine Block 12 at [2][2] | Value: $500

Net Profit for this pit: $100
