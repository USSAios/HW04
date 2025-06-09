#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std; // namespace std 사용

class Book {
public:
        string title;
        string author;

        Book(const string& title, const string& author)
                : title(title), author(author) {
        }
};

class BookManager {
private:
        vector<Book> books; // 책 목록 저장

public:
        // 책 추가 메서드
        void addBook(const string& title, const string& author) {
                books.push_back(Book(title, author)); // push_back 사용
                cout << "책이 추가되었습니다: " << title << " by " << author << endl;
        }

        Book* SearchByTitle(string title) {

                for (Book book : books) {

                        if (book.title == title) {
                                cout << "- " << book.title << " by " << book.author << endl;
                                return &book;
                        }                       
                }
              
                return 0;

        }

        Book* SearchByAuthor(string author) {

                for (Book book : books) {

                        if (book.author == author) {
                                cout << "- " << book.title << " by " << book.author << endl;
                                return &book;
                        }
                }
                return 0;
        }

        // 모든 책 출력 메서드
        void displayAllBooks() const {
                if (books.empty()) {
                        cout << "현재 등록된 책이 없습니다." << endl;
                        return;
                }

                cout << "현재 도서 목록:" << endl;
                for (size_t i = 0; i < books.size(); i++) { // 일반적인 for문 사용
                        cout << "- " << books[i].title << " by " << books[i].author << endl;
                }
        }
};

class BorrowManager{
private:
        unordered_map<Book*, int> stock;
        int quantity = 3;

public:

        void borrrowBook(Book* book) {
        
                if (book) {
                        if (stock.find(book) == stock.end()) {
                                stock[book] = quantity;
                        }
                        if (stock[book] > 0) {
                                stock[book]--;
                                cout << "책을 대출하였습니다" << endl;
                        }
                        else {
                                cout << "책의 재고가 없습니다" << endl;
                        }
                }
                else {
                        cout << "책을 찾을 수 없습니다." << endl;
                }
        }

        void returnBook(Book* book) {
                if (stock.find(book) == stock.end()) {
                        cout << "책을 찾을 수 없습니다." << endl;
                        return;
                }

                if (stock[book] > 0 && stock[book] < 3) {
                        stock[book]++;
                        cout << "책을 반납했습니다" << endl;
                        
                }
                else {
                        cout << "불가능한 조작입니다" << endl;
                }

        }

        void displayStock() {

        }

};

int main() {
        BookManager manager;
        BorrowManager borrowManager;

        // 도서관 관리 프로그램의 기본 메뉴를 반복적으로 출력하여 사용자 입력을 처리합니다.
        // 프로그램 종료를 선택하기 전까지 계속 동작합니다.
        while (true) {
                cout << "\n도서관 관리 프로그램" << endl;
                cout << "1. 책 추가" << endl; // 책 정보를 입력받아 책 목록에 추가
                cout << "2. 모든 책 출력" << endl; // 현재 책 목록에 있는 모든 책 출력
                cout << "3. 제목 검색" << endl;
                cout << "4. 저자 검색" << endl;
                cout << "5. 제목으로 책 빌리기" << endl;
                cout << "6. 저자이름으로 책 빌리기" << endl;
                cout << "7. 제목으로 반납하기" << endl;
                cout << "8. 저자이름으로 반납하기" << endl;
                cout << "9. 종료" << endl; // 프로그램 종료
                cout << "선택: ";

                int choice; // 사용자의 메뉴 선택을 저장
                cin >> choice;

                if (choice == 1) {
                        // 1번 선택: 책 추가
                        // 사용자로부터 책 제목과 저자명을 입력받아 BookManager에 추가합니다.
                        string title, author;
                        cout << "책 제목: ";
                        cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
                        getline(cin, title); // 제목 입력 (공백 포함)
                        cout << "책 저자: ";
                        getline(cin, author); // 저자명 입력 (공백 포함)
                        manager.addBook(title, author); // 입력받은 책 정보를 추가
                }
                else if (choice == 2) {
                        // 2번 선택: 모든 책 출력
                        // 현재 BookManager에 저장된 책 목록을 출력합니다.
                        manager.displayAllBooks();
                }
                else if (choice == 3) {
                        // 3번 선택: 책 제목 검색
                        string title;
                        Book* book;
                        cout << "책 제목: ";
                        cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
                        getline(cin, title);
                        book = manager.SearchByTitle(title);
                        if(book == 0)
                        {
                                cout << "책을 찾을수 없습니다" <<endl;
                        }
                }
                else if (choice == 4) {
                        // 4번 선택: 저자 검색
                        string author;
                        Book* book;
                        cout << "저자: ";
                        cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
                        getline(cin, author);
                        book = manager.SearchByAuthor(author);
                        if(book == 0)
                        {
                                 cout << "책을 찾을수 없습니다" << endl;
                        }
                }
                else if (choice == 5) {
                        // 5번 선택: 책 제목 으로 빌리기
                        string title;
                        Book* book;
                        cout << "책 제목: ";
                        cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
                        getline(cin, title);
                        book = manager.SearchByTitle(title);
                        borrowManager.borrrowBook(book);
                }
                else if (choice == 6) {
                        // 6번 선택: 저자이름으로 빌리기
                        string author;
                        Book* book;
                        cout << "저자: ";
                        cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
                        getline(cin, author);
                        book = manager.SearchByAuthor(author);
                        borrowManager.borrrowBook(book);
                }
                else if (choice == 7) {
                        //7번선택: 제목으로 반납하기
                        string title;
                        Book* book;
                        cout << "책 제목: ";
                        cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
                        getline(cin, title);
                        book = manager.SearchByTitle(title);
                        borrowManager.returnBook(book);
                }
                else if (choice == 8) {
                        //7번선택: 저자이름 으로 반납하기
                        string author;
                        Book* book;
                        cout << "저자: ";
                        cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
                        getline(cin, author);
                        book = manager.SearchByAuthor(author);
                        borrowManager.returnBook(book);
                }
                else if (choice == 9) {
                        // 3번 선택: 종료
                        // 프로그램을 종료하고 사용자에게 메시지를 출력합니다.
                        cout << "프로그램을 종료합니다." << endl;
                        break; // while 루프 종료
                }
                else {
                        // 잘못된 입력 처리
                        // 메뉴에 없는 번호를 입력했을 경우 경고 메시지를 출력합니다.
                        cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
                }
        }

        return 0; // 프로그램 정상 종료
}
