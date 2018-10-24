public class Worker {
    String name;
    int age;
    String position;
    double experience;

    Worker(String name, int age, String position, double experience) {
        this.name = name;
        this.age = age;
        this.position = position;
        this.experience = experience;
    }

    void getInfo() {
        System.out.printf("Имя: %s\n" +
                "Возраст: %s\n" +
                "Должность: %s\n" +
                "Опыт: %s\n", name, age, position, experience);
    }
}

