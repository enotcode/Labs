public class Manager extends Worker {
    int numberSales;

    Manager(String name, int age, String position, double experience, int numberSales) {
        super(name, age, position, experience);
        this.numberSales = numberSales;
    }

    @Override
    void getInfo() {
        System.out.printf("Имя: %s\n" +
                "Возраст: %s\n" +
                "Должность: %s\n" +
                "Опыт: %s\n" +
                "Количество продаж: %s\n\n", name, age, position, experience, numberSales);
    }
}
