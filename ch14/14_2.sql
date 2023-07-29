SELECT BuildingName, ISNULL(count,0) as 'Count'
FROM Buildings
LEFT JOIN 
 (SELECT Apartments.BuildingsID, count(*) as 'Count'
  FROM Requests INNER JOIN Apartments
  ON Requests.AptID = Apartments.AptID
  WHERE Requests.Status = 'Open'
  GROUP BY Apartments.BuildingID) ReqCounts
ON ReqCounts.BuildingID = Buildings.BuildingID
