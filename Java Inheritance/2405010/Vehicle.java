abstract class Vehicle 
{
    public static final double MAX_LIMIT=500000000.0;
    private String registrationNumber;
    private String ownerName;
    private double baseServiceCost;
    Vehicle(String reg,String owner,double cost)throws ServiceException
    {
        if((reg==null || reg.equals(""))&&(cost<0))
        {
            throw new ServiceException("Invalid Registration Number, It cannot be empty or null & Invalid cost, It must be positive");
        }
        else if(reg==null || reg.equals(""))
        {
            throw new ServiceException("Invalid Registration Number. It cannot be empty or null");
        }
        else if(cost<0)
        {
            throw new ServiceException("Invalid cost. It must be positive");
        }
        this.registrationNumber = reg;
        this.ownerName = owner;
        this.baseServiceCost = cost;
    }
    public void setNumber(String reg)
    {
        this.registrationNumber=reg;
    }
    public void setName(String name)
    {
        this.ownerName=name;
    }
    public void setCost(double cost)
    {
        this.baseServiceCost=cost;
    }
    public String getReg()
    {
        return this.registrationNumber;
    }
    public String getName()
    {
        return this.ownerName;
    }
    public double getCost()
    {
        return this.baseServiceCost;
    }
    abstract double getFinalCost() ;
    abstract void display();
}

class Car extends Vehicle implements Servicable
{
    private int numDoors;
    public Car(String reg, String owner, double cost, int numDoors) throws ServiceException
    {
        super(reg,owner,cost);
        this.numDoors=numDoors;
    }
    public void setDoors(int numbers)
    {
        this.numDoors=numbers;
    }
    public int getDoors()
    {
        return this.numDoors;
    }
    public void service() throws ServiceException
    {
        if(this.serviceCost()>MAX_LIMIT)
        {
            throw new ServiceException("Service Max Limit Exceeded. Cannot service anymore");
        }
        System.out.println("The car was serviced successfully with cost of "+this.getFinalCost());
    }
    public double serviceCost()
    {
        return this.getFinalCost();
    }
    @Override public double getFinalCost() 
    {
        double total;
        total=getCost()+numDoors*500.0;
        return total;
    }
    @Override public void display()
    {
        System.out.println("Vehicle Type: Car ,"+"Registration Number: "+this.getReg()+" ,Owner Name: "+this.getName()+" ,Number of Doors: "+ this.getDoors()+ " ,Total cost: "+ this.getFinalCost()+ " BDT.");
    }
}

class Bike extends Vehicle implements Servicable
{
    private double capacity;
    public Bike(String reg, String owner, double cost, double capacity) throws ServiceException
    {
        super(reg,owner,cost);
        this.capacity=capacity;
    }
    public void setCapacity(double capacity)
    {
        this.capacity=capacity;
    }
    public double getCapacity()
    {
        return this.capacity;
    }
    public void service() throws ServiceException
    {
        if(this.serviceCost()>MAX_LIMIT)
        {
            throw new ServiceException("Service Max Limit Exceeded. Cannot service anymore");
        }
        System.out.println("The Bike was serviced successfully with cost of "+this.getFinalCost());
    }
    public double serviceCost()
    {
        return this.getFinalCost();
    }
    @Override public double getFinalCost()
    {
        double total;
        total=getCost()+capacity*2.0;
        return total;
    }
    @Override public void display()
    {
        System.out.println("Vehicle Type: Bike ,"+"Registration Number: "+this.getReg()+" ,Owner Name: "+this.getName()+" ,Engine Capacity: "+ this.getCapacity()+ " ,Total cost: "+ this.getFinalCost()+ " BDT.");
    }
}

class Truck extends Vehicle implements Servicable
{
    private double capacity;
    public Truck(String reg, String owner, double cost, double capacity) throws ServiceException
    {
        super(reg,owner,cost);
        this.capacity=capacity;
    }
    public void setCapacity(double capacity)
    {
        this.capacity=capacity;
    }
    public double getCapacity()
    {
        return this.capacity;
    }
    public void service() throws ServiceException
    {
        if(this.serviceCost()>MAX_LIMIT)
        {
            throw new ServiceException("Service Max Limit Exceeded. Cannot service anymore");
        }
        System.out.println("The Truck was serviced successfully with cost of "+this.getFinalCost());
    }
    public double serviceCost()
    {
        return this.getFinalCost();
    }
    @Override public double getFinalCost()
    {
        double total;
        total=getCost()+capacity*1000.0;
        return total;
    }
    @Override public void display()
    {
        System.out.println("Vehicle Type: Truck ,"+"Registration Number: "+this.getReg()+" ,Owner Name: "+this.getName()+" ,Load Capacity: "+ this.getCapacity()+ " ,Total cost: "+ this.getFinalCost()+" BDT.");
    }
}


interface Servicable
{
    public void service() throws ServiceException;
    public double serviceCost() ; 
}