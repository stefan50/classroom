# SQL

## JOIN
SELECT * FROM first type_of_join JOIN second ON condition;
* INNER JOIN = returns only rows with the same value in both tables
* LEFT/RIGHT OUTER JOIN = returns from left/right and if there is from right/left, returns it
* FULL OUTER JOIN = returns both

EXAMPLE:
```sql
DROP DATABASE students;
CREATE DATABASE students; 
USE students;

CREATE TABLE Primes 
(
  NumberIdx int AUTO_INCREMENT,
  PrimeValue int,
  PRIMARY KEY (NumberIdx)
);

CREATE TABLE Fibonacci 
(
  NumberIdx int AUTO_INCREMENT,
  FibonacciValue int,
  PRIMARY KEY (NumberIdx) 
);

-- needs insertion

SELECT * FROM Primes p INNER JOIN Fibonacci f ON p.PrimeValue = f.FibonacciValue;
```

JOIN for more than one table: SELECT * FROM first type JOIN second ON condition type JOIN third ON condition;

Realisation of everything up until now:
```sql
DROP DATABASE school;
CREATE DATABASE school;
USE school;
CREATE TABLE students
(
    Name VARCHAR(100) NOT NULL,
    Num INTEGER NOT NULL,
    Class VARCHAR(3),
    EMark NUMERIC(3,2),
    PRIMARY KEY(Num,Class)
);
 
CREATE TABLE marks
(
    Id INTEGER AUTO_INCREMENT,
    StudentNum INTEGER NOT NULL,
    StudentClass VARCHAR(3) NOT NULL,
    SubjectName VARCHAR(100) NOT NULL,
    ExamDate DATE NOT NULL,
    Mark NUMERIC(3,2),
    PRIMARY KEY(Id)
);
 
INSERT INTO students
VALUES ('Mihail',1,'8a', 5.00);
 
INSERT INTO students
VALUES('Bogdan', 1,'8b', 3.00);
 
INSERT INTO students
VALUES('Petar', 3,'8v', 4.00);
 
INSERT INTO students
VALUES('Lilly', 4,'8a', 4.20);
 
INSERT INTO students
VALUES('Merry', 5,'8b', 2.00);
 
INSERT INTO students
VALUES('Henry', 2,'8a', 6.00);
 
INSERT INTO students
VALUES('James', 7,'8g', 6.00);
 
INSERT INTO marks (StudentNum, StudentClass, SubjectName, ExamDate, Mark)
SELECT Num,Class,'Math','2018-09-15', 5.00
FROM students
WHERE EMark >= 4.50;
 
INSERT INTO marks (StudentNum, StudentClass, SubjectName, ExamDate, Mark)
SELECT Num,Class,'Bulg','2018-09-13', 4.00
FROM students
WHERE EMark >= 3.50;
 
SELECT s.Name,s.Class,m.ExamDate,m.Mark FROM students s INNER JOIN marks m ON s.Num = m.StudentNum AND s.Class = m.StudentClass;
```
Or to select only NULL:
```sql
WHERE m.Mark IS NULL;
```
