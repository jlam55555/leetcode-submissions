# Write your MySQL query statement below
SELECT e1.Name AS Employee from Employee e1, Employee e2 WHERE e1.ManagerId=e2.id AND e1.Salary>e2.Salary;
