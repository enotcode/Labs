public class Main {
    public static void main(String args[]) {
        Manager manager = new Manager("Анна", 23, "Старший менеджер", 3, 409);
        manager.getInfo();

        Analyst analyst = new Analyst("Михаил", 30, "Ведущий аналитик", 7.5, 987);
        analyst.getInfo();

        Programmer programmer = new Programmer("Виктор", 19, "Junior-программист", 1.5, new String[]{"C++", "Java", "Python", "Swift"});
        programmer.getInfo();
    }
}
