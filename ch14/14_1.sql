SELECT TenantName
FROM Tenantes
INNER JOIN
(SELECT TenanteID FROM AptTenantes GROUP BY TenantID HAVING count(*)>1) call
ON Tenantes.TenantID= C.TenantID
