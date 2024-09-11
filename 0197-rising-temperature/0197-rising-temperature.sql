select w1.id 
from Weather w1
join Weather w2
on subdate(w1.recordDate,1)=w2.recordDate
and w1.temperature > w2.temperature;