#include <iostream>
#include <exception>
#include <string>

struct Person {
    /*
    x    - Point where Person is standing;
    x2   - Point where Person needs to get;
    time - time for which Person passes one meter.
    */
    int x, x2, time;

    Person() {
        x = x2 = time = 0;
    }
};

struct Shuttle {
    /*
    x         - Point where shuttle is standing;
    s         - Max point where shuttle can get;
    direction - direction in which the shuttle moves;
    time      - time for which shuttle passes one meter.
    */
   int x, direction, time, s;

   Shuttle () {
       x = direction = time = s = 0;
   }
};

/**
    Returns the time in seconds for which Person can get from point x1 to point x2.

    @param person Parameters of person.
    @return The time in seconds.
*/
int calculatePersonHimselfTime (Person person) {
    return person.x2 > person.x ? (person.x2 - person.x) * person.time : 
        (person.x - person.x2) * person.time;
}

/**
    Returns the time in seconds for which Shuttle can deliver Person to point x2.

    @param shuttle Parameters of person.
    @param personX Point where Person is standing;
    @param personX2 Point where Person needs to get;
    @return The time in seconds.
*/
int calculateShuttleTime (Shuttle shuttle, int personX, int personX2) {
    // Persons stands, shuttle pick up him along the way

    int shutttleTime = 0;

    if (personX < personX2) {
        if (shuttle.direction == 1) {
            if (shuttle.x <= personX) {
                // shuttle moves to point x2
                shutttleTime = (personX2 - shuttle.x) * shuttle.time;
            }
            else { 
                // shuttle moves to point s, then to point 0, then to point x2. 
                shutttleTime = (shuttle.s - shuttle.x) * shuttle.time + shuttle.s * shuttle.time + personX2 * shuttle.time;
            }
        }
        else {
            // shuttle moves to point 0, then to point x2.
            shutttleTime = shuttle.x * shuttle.time + personX2 * shuttle.time;
        }
    } 
    else {
        if (shuttle.direction == 1) {
            // shuttle moves to point s, then to point x2.
            shutttleTime = (shuttle.s - shuttle.x) * shuttle.time + (shuttle.s - personX2) * shuttle.time;
        }
        else if (shuttle.direction == -1) {
            if (shuttle.x <= personX) {
                // shuttle moves to point 0, then to point s, then to point x2.
                shutttleTime = shuttle.x * shuttle.time + shuttle.s * shuttle.time + (shuttle.s - personX2) * shuttle.time;
            }
            else {
                // shuttle moves to point x2.
                shutttleTime = (shuttle.x - personX2)* shuttle.time;
            }
        }
    }

    return shutttleTime;
}

/**
    Returns the minimum time in seconds for which Person can get from point x1 to point x2.

    @param person Parameters of person.
    @param shuttle Parameters of shuttle.
    @return The minimum time in seconds.
*/
int calculateMinTime (Person person, Shuttle shuttle) {
    int personTime = calculatePersonHimselfTime(person);
    
    // If personTime <= shuttleTime then person speed is greater
    // than shuttle speed, i.e. person moves faster then 
    // he don't heed a shuttle.
    if (person.time <= shuttle.time) {
        
        return personTime;
    }

    int shuttleTime = calculateShuttleTime(shuttle, person.x, person.x2);
    return shuttleTime < personTime ? shuttleTime : personTime; 
}

/**
    Write the input data into structures.

    @param person Parameters of person.
    @param shuttle Parameters of shuttle.
*/
void getInputData (Person *person, Shuttle *shuttle) {
    std::cin >> shuttle->s;
    if (shuttle->s < 2 && shuttle->s > 1000)
        throw "s parameter isn't correct.";

    std::cin >> person->x;
    std::cin >> person->x2;
    if (person->x < 0 || person->x > shuttle->s ||
        person->x2 < 0 || person->x2 > shuttle->s ||
        person->x == person->x2)
        throw "x1, x2 parameters isn't correct.";

    std::cin >> shuttle->time;
    std::cin >> person->time;
    if (person->time > 1000 || person->time < 0 ||
        shuttle->time > 1000 || shuttle->time < 0)
        throw "t1, t2 parameters isn't correct.";

    std::cin >> shuttle->x;
    if (shuttle->x < 1 || shuttle->x > shuttle->s - 1)
        throw "p parameter isn't correct.";

    std::cin >> shuttle->direction;
    if (shuttle->direction != 1 && shuttle->direction != -1) 
        throw "d parameter isn't correct.";
}

int main () {
    Person person;
    Shuttle shuttle;
    try {
        getInputData(&person, &shuttle);
    }
    catch (const char *exp) {
        std::cout << exp << std::endl;
    }
    std::cout << calculateMinTime(person, shuttle) << std::endl;

    return 0;
}