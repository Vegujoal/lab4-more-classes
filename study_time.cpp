/*
 * Course: COEN 2220 - Programming 2
 * Name: [Jose A Vera Guagua]
 * Lab: Lab 4 - Object-Oriented Programming, Part 2
 * Description: Guided example - static members, copies, and operators
 * Due date: [9/10/2026]
 */

#include <iostream>
using namespace std;

class StudyTime
{
    private:
        int minutes;               // Each object stores its own duration.
        static int objectCount;    // One counter is shared by the entire class.

    public:
        StudyTime(int m = 0) {
            minutes = m;
            objectCount++;         // Every new object increases the shared count.
        }

        int getMinutes() const { return minutes; }

        static int getObjectCount() {
            return objectCount;    // A static function reads class-level data.
        }

        // --- STEP 2: copy constructor (uncomment the /* ... */ block later) ---
        
        StudyTime(const StudyTime &other) {
            minutes = other.minutes;  // Copy the source object's duration.
            objectCount++;            // The copy is a new object too.
        }
        

        // --- STEP 3: operator+ (uncomment the /* ... */ block later) ---
        
        StudyTime operator+(const StudyTime &other) const {
            // Return a new duration without changing either operand.
            return StudyTime(minutes + other.minutes);
        }
        StudyTime& operator=(const StudyTime &other) = default; //operator= default to avoid compiler warning about missing operator=

        // ===== Resuelve estos TODO ahora (Parte E) =====

        // TODO (Parte E): Define operator== so two StudyTime objects are equal
        bool operator==(const StudyTime &other) const {
            return minutes == other.minutes;
        }
        // when they represent the same number of minutes. The function must not modify either object and must return a bool.
        
};

int StudyTime::objectCount = 0;    // Define the single shared variable.

int main() {
    // Create two StudyTime objects with same durations and one with a different duration.
    StudyTime study1(30);  // 30 minutes
    StudyTime study2(30);  // 30 minutes
    StudyTime study3(45);  // 45 minutes
    // Imprime el resultado de al menos dos comparaciones, usando boolalpha para que la salida diga true o false
    cout << "Comparing study1 and study2: " << boolalpha << (study1 == study2) << endl; 
    cout << "Comparing study1 and study3: " << boolalpha << (study1 == study3) << endl; 
    
    return 0;
}