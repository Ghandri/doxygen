// objective: test the \extends, \implements, \memberof, \private, and \public commands
// check: struct_object.xml
// check: struct_vehicle.xml
// check: struct_car.xml
// check: struct_truck.xml

/**
 * \file 
 */

typedef struct Object Object;   //!< Object type
typedef struct Vehicle Vehicle; //!< Vehicle type
typedef struct Car Car;         //!< Car type
typedef struct Truck Truck;     //!< Truck type

/*!
 * Base object class.
 */
struct Object
{
  int ref;    //!< \private Reference count.
};


/*!
 * Increments object reference count by one.
 * \public \memberof Object
 */
static Object * objRef(Object *obj);


/*!
 * Decrements object reference count by one.
 * \public \memberof Object
 */
static Object * objUnref(Object *obj);


/*!
 * Vehicle class.
 * \extends Object
 */
struct Vehicle
{
  Object base;    //!< \protected Base class.
};


/*!
 * Starts the vehicle.
 * \public \memberof Vehicle
 */
void vehicleStart(Vehicle *obj);


/*!
 * Stops the vehicle.
 * \public \memberof Vehicle
 */
void vehicleStop(Vehicle *obj);


/*!
 * Car class.
 * \implements Vehicle
 */
struct Car
{
  Vehicle base;    //!< \protected Base class.
};


/*!
 * Truck class.
 * \implements Vehicle
 */
struct Truck
{
  Vehicle base;    //!< \protected Base class.
};


/*!
 * Main function.
 *
 * Ref vehicleStart(), objRef(), objUnref().
 */
int main(void)
{
  Car c;
  vehicleStart((Vehicle*) &c);
}

