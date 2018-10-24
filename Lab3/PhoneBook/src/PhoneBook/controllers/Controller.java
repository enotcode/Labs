package PhoneBook.controllers;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import PhoneBook.models.Book;

import javafx.scene.control.TableColumn;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Controller {
    private ObservableList<Book> Data = FXCollections.observableArrayList();

    @FXML
    private TableView<Book> tableBook;

    @FXML
    private TableColumn<Book, Integer> idColumn;

    @FXML
    private TableColumn<Book, String> fromColumn;

    @FXML
    private TableColumn<Book, String> toColumn;

    @FXML
    private TableColumn<Book, String> dateColumn;

    @FXML
    private TableColumn<Book, String> timeColumn;

    @FXML
    private TableColumn<Book, Double> durationColumn;

    @FXML
    private void initialize() throws FileNotFoundException {
        initData();
        idColumn.setCellValueFactory(new PropertyValueFactory<>("id"));
        fromColumn.setCellValueFactory(new PropertyValueFactory<>("from"));
        toColumn.setCellValueFactory(new PropertyValueFactory<>("to"));
        dateColumn.setCellValueFactory(new PropertyValueFactory<>("date"));
        timeColumn.setCellValueFactory(new PropertyValueFactory<>("time"));
        durationColumn.setCellValueFactory(new PropertyValueFactory<>("duration"));

        tableBook.setItems(Data);
    }

    private void initData() throws FileNotFoundException {
        Scanner in = new Scanner(new File("res/data.txt"));
        String s;
        int k = 0;
        while (in.hasNextLine()) {
            k++;
            s = in.nextLine();
            String w[] = s.split(" ");
            for (int i = 0; i < w.length - 4; i++)
                Data.add(new Book(k, w[i], w[i + 1], w[i + 2], w[i + 3], Double.parseDouble(w[i + 4])));
        }
        in.close();

    }

}