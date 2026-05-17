public class EmployeeExample {

    // Employee Interface
    public interface Employee {
        // Method to calculate the monthly salary
        double calculateMonthlySalary();
    }

    // SalariedEmployee Class
    public static class SalariedEmployee implements Employee {
        private String name;
        private double annualSalary;

        // Constructor
        public SalariedEmployee(String name, double annualSalary) {
            this.name = name;
            this.annualSalary = annualSalary;
        }

        // Implementing the calculateMonthlySalary method
        @Override
        public double calculateMonthlySalary() {
            return annualSalary / 12;  // Divide annual salary by 12 to get monthly salary
        }

        // Getter methods
        public String getName() {
            return name;
        }

        public double getAnnualSalary() {
            return annualSalary;
        }
    }

    // HourlyEmployee Class
    public static class HourlyEmployee implements Employee {
        private String name;
        private double hourlyRate;
        private double hoursWorked;

        // Constructor
        public HourlyEmployee(String name, double hourlyRate, double hoursWorked) {
            this.name = name;
            this.hourlyRate = hourlyRate;
            this.hoursWorked = hoursWorked;
        }

        // Implementing the calculateMonthlySalary method
        @Override
        public double calculateMonthlySalary() {
            return hourlyRate * hoursWorked * 4;  // Assuming 4 weeks per month
        }

        // Getter methods
        public String getName() {
            return name;
        }

        public double getHourlyRate() {
            return hourlyRate;
        }

        public double getHoursWorked() {
            return hoursWorked;
        }
    }

    // Main Class to Test
    public static void main(String[] args) {
        // Create SalariedEmployee and HourlyEmployee objects
        Employee salariedEmployee = new SalariedEmployee("Alice", 60000);  // Annual salary
        Employee hourlyEmployee = new HourlyEmployee("Bob", 20, 160);      // Hourly rate, hours worked per month

        // Print monthly salary of both employees
        System.out.println("SalariedEmployee " + ((SalariedEmployee) salariedEmployee).getName() 
                + "'s Monthly Salary: $" + salariedEmployee.calculateMonthlySalary());
        System.out.println("HourlyEmployee " + ((HourlyEmployee) hourlyEmployee).getName() 
                + "'s Monthly Salary: $" + hourlyEmployee.calculateMonthlySalary());
    }
}
