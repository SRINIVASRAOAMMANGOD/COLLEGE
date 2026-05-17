class Vehicle {
    String make;
    String model;

    public Vehicle(String make, String model) {
        this.make = make;
        this.model = model;
    }

    public void displayDetails() {
        System.out.println("Make: " + make + ", Model: " + model);
    }
}

class Car extends Vehicle {
    int doors;

    public Car(String make, String model, int doors) {
        super(make, model);  // Calling the superclass constructor
        this.doors = doors;
    }

    @Override
    public void displayDetails() {
        super.displayDetails();
        System.out.println("Doors: " + doors);
    }
}

class Truck extends Vehicle {
    double payloadCapacity;

    public Truck(String make, String model, double payloadCapacity) {
        super(make, model);  // Calling the superclass constructor
        this.payloadCapacity = payloadCapacity;
    }

    @Override
    public void displayDetails() {
        super.displayDetails();
        System.out.println("Payload Capacity: " + payloadCapacity + " tons");
    }
}
class Main1{
    public static void main(String[] args) {
        Car car=new Car("hun","m1",4);
        Truck t=new Truck("nuh","n2",7);
        car.displayDetails();
        t.displayDetails();
    }
}