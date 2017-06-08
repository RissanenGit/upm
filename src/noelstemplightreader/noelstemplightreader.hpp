#pragma once

#include <string>

#include "interfaces/iMraa.hpp"
#include "interfaces/iLightSensor.hpp"
#include "interfaces/iTemperatureSensor.hpp"

namespace upm
{
    /**
     * Example class to show multiple inheritance of sensor interfaces.
     *
     * This sensor provides light, temperature, and uses MRAA.
     */
    class NoelsTempLightReader :
        public virtual iLightSensor,
        public virtual iTemperatureSensor,
        public virtual iMraa
    {
        public:
            static std::string AdditionalSerializer(NoelsTempLightReader * inst)
            {
                return "\"some other field\" : \"value\"";
            }

            /**
             * Add the source:units map values for this sensor
             */
            NoelsTempLightReader()
            {
                AddSource("light0", "lux");
                AddSource("light1", "lux");
                AddSource("temperature0", "c");
                AddSource("temperature1", "c");
                _children[(t_getJson)&AdditionalSerializer] = this;
            }

            /* Provide the sensor name */
            virtual std::string Name() const {return "LightTemp9000";}
            /* Provide a brief sensor description */
            virtual std::string Description() const {return "This is the best light and temperature sensor ever";}
            /* Expose all base methods for Light */
            using iLightSensor::Light;
            /* Provide an implementation of a method to get sensor values by source */
            virtual std::map<std::string, float> Light(std::vector<std::string> sources);
            /* Expose all base methods for Temperature */
            using iTemperatureSensor::Temperature;
            /* Provide an implementation of a method to get sensor values by source */
            virtual std::map<std::string, float> Temperature(std::vector<std::string> sources);
    };
}
