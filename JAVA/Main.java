import java.util.*;
class Employee {
   	 String name;
    	double salary;
public Employee(String name, double salary) {
        		this.name = name;
        		this.salary = salary;
    	}
public double calculateBonus() {
        		return 0;
 }
public void displayDetails() {
        		System.out.println("Employee Name: " + name);
        		System.out.println("Salary: " + salary);
        		System.out.println("Bonus: " + calculateBonus());
    	}
}
class Manager extends Employee {
    	private static double FIXED_BONUS = 5000;
public Manager(String name, double salary) {
        		super(name, salary);
}
public double calculateBonus() {
        	return FIXED_BONUS;
}
}
class Developer extends Employee {
 double performanceRating;
public Developer(String name, double salary, double performanceRating) {
        			super(name, salary);
        			this.performanceRating = performanceRating;
}
public double calculateBonus() {
        			return salary * (performanceRating / 10);
}
}
public class Main {
    		public static void main(String[] args) {
        		List<Employee> employees = new ArrayList<>();
        		employees.add(new Manager("Vishal", 80000));
        	employees.add(new Developer("Surya", 60000, 8.5));
        		employees.add(new Developer("Shibu", 60000, 6.0));
for (Employee emp : employees) {
            			emp.displayDetails();
            			System.out.println("\n");
        		}
    		}	}
