class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Line:
    def __init__(self, start : Point, end : Point):
        self.start = start
        self.end = end

class Square:
    def __init__(self, left,  top, size):
        self.left = left
        self.top = top
        self.right = left + size
        self.bottom = top + size
        self.size = size

    def middle(self) -> Point:
        return Point((self.left + self.right)/2, (self.top + self.bottom)/2)

   def dir(self, x1, x2) -> int:
        if x1 < x2:
            return -1
        else:
            return 1

    def extend(self, mid1, mid2, size) -> Point:
        xdir = self.dir(mid1.x, mid2.x)
        ydir = self.dir(mid1.y, mid2.y)

        if mid1.x == mid2.x:
            return Point(mid1.x, mid1.y +ydir*size/2);

        slope = (mid1.y- mid2.y)/ (mid1.x - mid2.x)

        x1 = 0
        y1 = 0

        if abs(slope) == 1 :
            x1 = mid1.x + (xdir*size)/2
            y1 = mid1.y + (ydir*size)/2
        elif abs(slope) < 1:
            x1 = mid1.x + (xdir*size)/2
            y1 =slope*(x1-mid1.x) + mid1.y
        else:
            y1 = mid1.y + (ydir*size)/2
            x1= (y1 - mid1.y)/(slope + mid1.x)

        return Point(x1,y1)

def cut(me : Square, other : Square) -> Line:
    p1 = me.extend(me.middle(), other.middle(), me.size)
    p2 = me.extend(me.middle(), other.middle(), -1* me.size)
    p3 = other.extend(other.middle(), me.middle(), other.size)
    p4 = other.extend(other.middle(), me.middle(), -1* other.size)

    list = {p2,p3,p4}

    s = p1
    e = p1

    for p in list:
        if p.x < s.x or p.x==s.x and p.y < s.y:
            s = p
        elif p.x > e.x or p.x == e.x and p.y > e.y:
            e =p

    return Line(s,e)
