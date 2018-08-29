#ifndef OBSERVER_PATTERN_WEATHERDATA_HPP
#define OBSERVER_PATTERN_WEATHERDATA_HPP

#include <vector>
#include <algorithm>
#include <iostream>

#include "Observable.hpp"
#include "Observer.hpp"

/**
 * A concrete implementation of the Observable interface
 */
class WeatherData : public Observable {
    std::vector<Observer *> observers; // observers

    float temp = 0.0f;
    float humidity = 0.0f;
    float pressure = 0.0f;

public:

    void registerObserver(Observer *observer) override;

    void removeObserver(Observer *observer) override;

    void notifyObservers() override;

    /**
     * Set the new state of the weather station
     * @param temp new temperature
     * @param humidity new humidity
     * @param pressure new pressure
     */
    void setState(float temp, float humidity, float pressure);

};


#endif //OBSERVER_PATTERN_WEATHERDATA_HPP