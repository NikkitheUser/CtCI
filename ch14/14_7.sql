SELECT StudentName, GPA
FROM(SELECT AVG(CourseEnrollment.Grade)AS GPA, CourseEnrollment.StudentID
  FROM CourseEnrollment
  GROUP BY CourseEnrollment.StudentID
  HAVING AVG(CourseEnrollment.Grade)>=@GPACutOff)Honors
INNER JOIN Students ON Honors.StudentID = Student.StudentID
