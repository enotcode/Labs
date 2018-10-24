import java.util.Arrays;

public class Programmer extends Worker {
    String langs[];

    Programmer(String name, int age, String position, double experience, String langs[]) {
        super(name, age, position, experience);
        this.langs = langs;
    }

    @Override
    void getInfo() {
        System.out.printf("Имя: %s\n" +
                "Возраст: %s\n" +
                "Должность: %s\n" +
                "Опыт: %s\n", name, age, position, experience);
        System.out.print("Языки программирования: ");
        for (int i = 0; i < langs.length; i++)
            System.out.print(langs[i] + ", ");
    }
}
