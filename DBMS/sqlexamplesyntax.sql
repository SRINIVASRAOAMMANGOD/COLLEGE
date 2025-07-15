DDL
-- Create a new database
CREATE DATABASE database_name;

-- Remove a database
DROP DATABASE database_name;

-- Select a database to work on
USE database_name;

-- Create a new table
CREATE TABLE table_name (
    column1 datatype constraints,
    column2 datatype constraints,
    ...
);

-- Modify table: Add a column
ALTER TABLE table_name ADD column_name datatype;

-- Modify table: Drop a column
ALTER TABLE table_name DROP COLUMN column_name;

-- Modify table: Change column definition
ALTER TABLE table_name MODIFY column_name new_datatype;

-- Rename a table
RENAME TABLE old_table_name TO new_table_name;

-- Delete an entire table (structure and data)
DROP TABLE table_name;

DML
-- Add new data to a table
INSERT INTO table_name (column1, column2) VALUES (value1, value2);

-- Alternative syntax for inserting
INSERT INTO table_name SET column1 = value1, column2 = value2;

-- Read data from table
SELECT column1, column2 FROM table_name;

-- Read all columns from table
SELECT * FROM table_name;

-- Update existing data
UPDATE table_name SET column1 = new_value WHERE condition;

-- Delete specific rows
DELETE FROM table_name WHERE condition;

-- Remove all rows but keep the table structure
TRUNCATE TABLE table_name;

DQL
-- Select specific columns from a table
SELECT username, age FROM users WHERE status = 'active';

-- Select all columns
SELECT * FROM users;

-- Select with sorting
SELECT username FROM users ORDER BY registered_at DESC;

-- Select with grouping
SELECT status, COUNT(*) FROM users GROUP BY status;

DCL
-- Create a new user account
CREATE USER 'newuser'@'localhost' IDENTIFIED BY 'strongpassword';

-- Grant all privileges on a database to the user
GRANT ALL PRIVILEGES ON mydb.* TO 'newuser'@'localhost';

-- Limit privileges (read-only)
GRANT SELECT ON mydb.* TO 'readonly'@'localhost';

-- Revoke privileges
REVOKE ALL PRIVILEGES ON mydb.* FROM 'readonly'@'localhost';


TCL
-- Start a transaction
START TRANSACTION;

-- Run multiple data changes
UPDATE accounts SET balance = balance - 500 WHERE id = 1;
UPDATE accounts SET balance = balance + 500 WHERE id = 2;

-- If all queries worked, commit the transaction
COMMIT;

-- If something went wrong, cancel the changes
ROLLBACK;

Numeric Function Syntax
SELECT ABS(-5);                     -- Returns 5
SELECT CEIL(4.2);                   -- Returns 5
SELECT FLOOR(4.9);                  -- Returns 4
SELECT ROUND(4.567, 2);             -- Returns 4.57
SELECT MOD(10, 3);                  -- Returns 1
SELECT POWER(2, 3);                 -- Returns 8
SELECT RAND();                      -- Returns a random number (0–1)

Date and Time Function Syntax
SELECT NOW();                       -- Current date & time
SELECT CURDATE();                   -- Current date
SELECT CURTIME();                   -- Current time
SELECT DATE_ADD(NOW(), INTERVAL 5 DAY);   -- Adds 5 days
SELECT DATEDIFF('2025-07-20', '2025-07-15'); -- Difference in days
SELECT YEAR('2025-07-15');          -- Returns 2025
SELECT MONTH('2025-07-15');         -- Returns 7
SELECT DAY('2025-07-15');           -- Returns 15


String/Text Function Syntax
SELECT CONCAT('Hello', 'World');         -- HelloWorld
SELECT LENGTH('MySQL');                  -- Returns 5
SELECT LOWER('HELLO');                   -- hello
SELECT UPPER('hello');                   -- HELLO
SELECT SUBSTRING('Copilot', 2, 3);       -- Returns 'opi'
SELECT TRIM('  hello  ');                -- Returns 'hello'
SELECT REPLACE('red car', 'red', 'blue');-- Returns 'blue car'


Logical and Comparison Function Syntax
SELECT IF(5 > 3, 'Yes', 'No');           -- Returns 'Yes'
SELECT NULLIF(5, 5);                     -- Returns NULL
SELECT COALESCE(NULL, '', 'Hi');         -- Returns ''

Aggregate Functions
SELECT COUNT(*) FROM users;              -- Total rows
SELECT SUM(salary) FROM employees;       -- Total salary
SELECT AVG(score) FROM results;          -- Average score
SELECT MAX(price) FROM products;         -- Highest price
SELECT MIN(price) FROM products;         -- Lowest price


CREATE TWO TABLE INTERLINKED 
CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50) NOT NULL,
    email VARCHAR(100)
);
CREATE TABLE orders (
    id INT AUTO_INCREMENT PRIMARY KEY,
    user_id INT,
    product_name VARCHAR(100) NOT NULL,
    order_date DATE,

    FOREIGN KEY (user_id) REFERENCES users(id)
);
-- Insert a user
INSERT INTO users (username, email) VALUES ('john_doe', 'john@example.com');

-- Insert an order for user with id = 1
INSERT INTO orders (user_id, product_name, order_date) VALUES (1, 'Laptop', '2025-07-16');

WITH CASACDE
CREATE TABLE orders (
    id INT AUTO_INCREMENT PRIMARY KEY,
    user_id INT,
    product_name VARCHAR(100) NOT NULL,
    order_date DATE,
    FOREIGN KEY (user_id)
        REFERENCES users(id)
        ON DELETE CASCADE
);
