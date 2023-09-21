#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structures section
struct Race {
  int numberOfLaps;
  int currentLap;
  char* firstPlaceDriverName;
  char* firstPlaceRaceCarColor;
};

struct RaceCar {
  char* driverName;
  char* raceCarColor;
  int totalLapTime;
};

// Print functions section

void printIntro() {
  printf("Welcome to Race Game\n");
}

void printCountDown() {
  printf("Racers Ready! In...\n");
  for(int i = 5; i > 0; i--) {
    printf("%d\n", i);
  }
  printf("Race!\n");
}

void printFirstPlaceAfterLap(struct Race* race) {
    printf("%s is leading the race\n", race->firstPlaceDriverName);
}

void printCongrats() {
    printf("Let's all congratulate Cosmo in the orange race car for an amazing performance.\n");
}

// Logic functions section

int calculateTimeToCompleteLap() {
    int speed = (rand() % 10) + 1;
    int acceleration = (rand() % 10) + 1;
    int nerves = (rand() % 10) + 1;

    return speed + acceleration + nerves;
}

void updateRaceCar(struct RaceCar* car) {
    car->totalLapTime = calculateTimeToCompleteLap();
}

void updateFirstPlace(struct Race* race, struct RaceCar* car1, struct RaceCar* car2) {
    if(car1->totalLapTime <= car2->totalLapTime) {
        race->firstPlaceDriverName = car1->driverName;
        race->firstPlaceRaceCarColor = car1->raceCarColor;
    } else {
        race->firstPlaceDriverName = car2->driverName;
        race->firstPlaceRaceCarColor = car2->raceCarColor;
    }
}

void startRace(struct RaceCar* car1, struct RaceCar* car2) {
    struct Race race = {
        5,
        1,
        "",
        ""
    };

    for(int lap = 0; lap < race.numberOfLaps; lap++) {
        updateRaceCar(car1);
        updateRaceCar(car2);
        updateFirstPlace(&race, car1, car2);
        printFirstPlaceAfterLap(&race);
    }

    printCongrats();
}

int main() {
    srand(time(0));
    printIntro();
    printCountDown();

    struct RaceCar car1 = { "Ilia", "Black" };
    struct RaceCar car2 = { "Sandro", "White" };

    startRace(&car1, &car2);
};