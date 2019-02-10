# Library Database

## 1 -  Consider the following schema for a Library Database:
BOOK(Book_id, Title, Publisher_Name, Pub_Year)

BOOK_AUTHORS(Book_id, Author_Name)

PUBLISHER(Name, Address, Phone)

BOOK_COPIES(Book_id, Branch_id, No-of_Copies)

BOOK_LENDING(Book_id, Branch_id, Card_No, Date_Out, Due_Date)

LIBRARY_BRANCH(Branch_id, Branch_Name, Address)

Write SQL queries to

1.	Retrieve details of all books in the library – id, title, name of publisher, authors, number of copies in each branch, etc.

2.	Get the particulars of borrowers who have borrowed more than 3 books, but from Jan 2017 to Jun 2017.

3.	Delete a book in BOOK table. Update the contents of other tables to reflect this data manipulation operation.

4.	Partition the BOOK table based on year of publication. Demonstrate its working with a simple query.

5.	Create a view of all books and its number of copies that are currently available in the Library.
