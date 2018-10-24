public class Analyst extends Worker {
    int numberForecasts;

    Analyst(String name, int age, String position, double experience, int numberForecasts) {
        super(name, age, position, experience);
        this.numberForecasts = numberForecasts;
    }

    @Override
    void getInfo() {
        System.out.printf("Имя: %s\n" +
                "Возраст: %s\n" +
                "Должность: %s\n" +
                "Опыт: %s\n" +
                "Количество прогнозов: %s\n\n", name, age, position, experience, numberForecasts);
    }
}
