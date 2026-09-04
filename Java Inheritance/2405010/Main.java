import java.util.Scanner;

public class Main{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        WorkshopManager workshop=new WorkshopManager();
        System.out.println("------------- MECHANIK: Vehicle Management System-------------");
        String registrationNumber;
        String owner;
        double baseCost;
        while(true)
        {
            try
            {
                System.out.println("Please Enter Car/Bike/Truck to add vehicles. You can enter Exit to stop entering vehicles console");
                String command=sc.nextLine();
                if(command.equals("Car"))
                {
                    System.out.print("Enter registration Number : ");
                    registrationNumber=sc.nextLine();
                    System.out.print("Enter owner Name : ");
                    owner=sc.nextLine();
                    System.out.print("Enter base cost : ");
                    baseCost=sc.nextDouble();
                    System.out.print("Enter the number of doors : ");
                    int doors=sc.nextInt();
                    Car newCar=new Car(registrationNumber,owner,baseCost,doors);
                    newCar.service();
                    workshop.addVehicle(newCar);
                }
                else if(command.equals("Bike"))
                {
                    System.out.print("Enter registration Number : ");
                    registrationNumber=sc.nextLine();
                    System.out.print("Enter owner Name : ");
                    owner=sc.nextLine();
                    System.out.print("Enter base cost : ");
                    baseCost=sc.nextDouble();
                    System.out.print("Enter engine capacity : ");
                    double capacity=sc.nextDouble();
                    Bike newBike=new Bike(registrationNumber,owner,baseCost,capacity);
                    newBike.service();
                    workshop.addVehicle(newBike);
                }
                else if(command.equals("Truck"))
                {
                    System.out.print("Enter registration Number : ");
                    registrationNumber=sc.nextLine();
                    System.out.print("Enter owner Name : ");
                    owner=sc.nextLine();
                    System.out.print("Enter base cost : ");
                    baseCost=sc.nextDouble();
                    System.out.print("Enter load capacity : ");
                    double capacity=sc.nextDouble();
                    Truck newTruck=new Truck(registrationNumber,owner,baseCost,capacity);
                    newTruck.service();
                    workshop.addVehicle(newTruck);
                }
                else if(command.equals("Exit"))
                {
                    break;
                }
                else
                {
                    System.out.println("Unknown command.Please check your command Uppercase/Lowercases.Press Enter to input a valid command- Car/Truck/Bike/Exit");
                }
                sc.nextLine();
            }
            catch (ServiceException service)
            {
                System.out.println("INPUT ERROR(INVALID FORMATS ENTERED)" + service.getMessage());
                sc.nextLine();
            }
            catch(Exception others)
            {
                System.out.println("UNRECOGNIZED ERROR");
                sc.nextLine();
            }
            finally
            {
                System.out.println("----------------------------------------------");
            }
        }
    workshop.displayDetails();
    System.out.println("Total Revenue for Today: " + workshop.calculateTotal() + " BDT");
    sc.close();
    }
}