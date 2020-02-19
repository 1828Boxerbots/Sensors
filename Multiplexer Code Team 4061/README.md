# README #

Example code (Work In Progress) for accessing REV Color Sensor V3 and 
REV 2m Distance Sensor through an Adafruit TCA9548A I2C multiplexer.

This code is provided by the Palouse SciBorgs, FRC Team 4061. There are no warranties,
use at your own risk.

As of this publication, the code is working on our robot. The `example.cpp` and `example.h` are
intended to be suggestive of use rather than actual, compilable code.

We have tested this code with 2 distance sensors and 1 color sensor on one multiplexer. We believe
there are no issues with using up to 8 sensors on the multiplexer, although we have some concern
that probing every sensor in every robot cycle may add too much time to the robot cycle time.

### Use ###
To use this code you need to install the `vendordeps` files for the Rev ColorSensorV3 and the Rev 2mDistanceSensor following the directions for those libraries. Note that there is currently (as of Release v2020.0.3) a bug in the `REV2mDistanceSensor.json` that causes gradle to fail to deploy all the necessary libraries to the robot even though code builds correctly. To fix this, in the `cppDependencies` section pertaining to `"libName": "libDistanceSensorDriver"`, change `"sharedLibrary": false` to `"sharedLibrary": true`.

### What next ###

* The PsbRev2mDistanceSensor module is only minimally changed from what REV originally
provided. Since there is functionality in there that is not compatible with using the multiplexer it
would be better to refactor PsbRev2mDistanceSensor and PSBDistanceSensor to provide all that
can be supported and nothing more. In particular, the Automatic feature of the REV distance
sensor class is incompatible with the approach used here.

### Conceptual Design ###
Classes `PSBColorSensor` and `PSBDistanceSensor` are wrappers for the REV sensor libraries that, before
issuing a command to a sensor, first use the I2CBreakout class to connect the downstream bus on which
the sensor resides to the upstream bus that is connected to the RoboRio.

`PSBColorSensor` and `PSBDistanceSensor` implement
only a minimal set of methods -- sufficient to serve as an example and, to our current understanding,
sufficient for the uses we intend for the sensors. Additional methods from the REV classes can be
wrapped similarly to what is seen here, except as noted above, the Automatic methods from the REV distance
sensor class absolutely will not play nicely with the approach used here. In fact, the simple rule is
that "all access to sensors connected to a given multiplexer MUST be made from the same thread".

### Who do I talk to? ###

* Email me: carl dot hauser at gmail dot com
