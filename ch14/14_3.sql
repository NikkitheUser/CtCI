UPDATE Requests
SET status ='Closed'
WHERE AptID IN(SELECT AptID FROM Apartments WHERE BuildingID=11)
