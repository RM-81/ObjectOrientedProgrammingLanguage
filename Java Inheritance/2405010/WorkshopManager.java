public class WorkshopManager
{
    private Vehicle [] vehicles;
    private int vehicleCount;
    public static final int MAX_VEHICLE=500000000;

    WorkshopManager()
    {
        this.vehicles=new Vehicle[MAX_VEHICLE];
        this.vehicleCount=0;
    }
    public void addVehicle(Vehicle vehicle)
    {
        if(vehicleCount<MAX_VEHICLE)
        {
            this.vehicles[vehicleCount]=vehicle;
            this.vehicleCount++;
            System.out.println("Vehicle added successfully");
        }
        else
        {
            System.out.println("Vehicle Garage Full. Cannot add more");
        }    
    }
    public void displayDetails()
    {
        System.out.println("-------------Vehicle list-------------");
        if(vehicleCount==0)
        {
            System.out.println("Inventory Empty");
        }
        else
        {
            for(int i=0;i<vehicleCount;i++)
            {
                this.vehicles[i].display();
            }
        }
    }
    public double calculateTotal()
    {
        double netRevenue=0.0;
        for(int i=0;i<vehicleCount;i++)
        {
            netRevenue=netRevenue+this.vehicles[i].getFinalCost();
        }
        return netRevenue;
    }
}
