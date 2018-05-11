
CREATE DATABASE library;

USE library;

CREATE TABLE authors
(
	Id INTEGER AUTO_INCREMENT,
    Name VARCHAR(50),
    PRIMARY KEY(Id)
);

CREATE TABLE books 
(
	Name VARCHAR(50) NOT NULL,
    YearOfBook YEAR NOT NULL,
    ISBN VARCHAR(17) NOT NULL,
    AuthorId INTEGER NOT NULL,
    FOREIGN KEY(AuthorId) REFERENCES authors(Id),
    PRIMARY KEY(ISBN)
);

CREATE TABLE book_authors
(
	AuthorId INTEGER,
    BookISBN VARCHAR(17),
	FOREIGN KEY(AuthorId) REFERENCES authors(Id),
	FOREIGN KEY(BookISBN) REFERENCES books(ISBN)
);

INSERT INTO authors(Name)
VALUES('Terry Pratchett');

INSERT INTO authors(Name)
VALUES('Stephen King');

INSERT INTO authors(Name)
VALUES('E. L. James');

INSERT INTO authors(Name)
VALUES('A. A. Milne');

INSERT INTO authors(Name)
VALUES('Karina Kozarova');

INSERT INTO authors(Name)
VALUES('Stephen King');

INSERT INTO books
VALUES('The Light Fantastic', 1982, '978-0062225689', 1);

INSERT INTO books
VALUES('The Light Fantastic', 1982, '978-0062225889', 1);

INSERT INTO books
VALUES('It', 1987, '978-0062225684', 2);

INSERT INTO books
VALUES('Fifty Shades Of Gray', 2010, '978-0062215684', 3);

INSERT INTO books
VALUES('Winnie the Pooh', 1960, '968-0062225684', 4);

INSERT INTO books
VALUES('The Glass Break', 1982, '968-0062222684', 2);

INSERT INTO book_authors
VALUES (1,'978-0062225689');

INSERT INTO book_authors
VALUES (2,'978-0062225689');

INSERT INTO book_authors
VALUES (2,'978-0062225684');

INSERT INTO book_authors
VALUES (3,'978-0062215684');

INSERT INTO book_authors
VALUES (4,'968-0062225684');

INSERT INTO book_authors
VALUES (2,'968-0062222684');

INSERT INTO book_authors
VALUES (1,'978-0062225889');

INSERT INTO book_authors
VALUES (2,'978-0062225889');


-- 1
SELECT Name FROM books WHERE YearOfBook=1982;

-- 2
SELECT b.Name, b.YearOfBook, b.ISBN FROM books b
INNER JOIN authors a ON a.Id = b.AuthorId
WHERE a.Name = 'Terry Pratchett';

-- 3
SELECT a.Name FROM authors a 
INNER JOIN book_authors ba ON a.Id = ba.AuthorId
WHERE ba.BookISBN = '978-0062225689';

-- 4
SELECT COUNT(ba.BookISBN),a.Name FROM book_authors ba 
RIGHT JOIN authors a ON a.Id= ba.AuthorId
GROUP BY a.Name,a.Id
ORDER BY COUNT(ba.BookISBN) DESC;

-- 5
SELECT  b.Name,COUNT(ba.AuthorId) FROM books b
LEFT JOIN book_authors ba ON b.ISBN= ba.BookISBN
INNER JOIN authors a on b.AuthorId=a.Id
WHERE  b.YearOfBook=1982
GROUP BY b.Name,b.ISBN
HAVING COUNT(ba.AuthorId)>=2 
ORDER BY b.Name ASC;
