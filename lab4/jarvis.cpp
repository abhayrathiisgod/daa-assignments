#include <bits/stdc++.h>
using namespace std;

// Struct for storing the points
struct Point{
    public:
    int xc, yc;
    Point(){
        xc=0;
        yc=0;
    }
    
    Point(int x,int y){
        xc=x;
        yc=y;
    }
};

// Comperator for set
struct compare{
    bool operator()(const Point& a, const Point& b) const{
        return a.xc < b.xc or (a.xc == b.xc and a.yc < b.yc);
    }
};

// Function to check the direction is anti-clockwise or not
int check_direction(Point a, Point b, Point c) {
    return (b.yc - a.yc) * (c.xc - b.xc) - (b.xc - a.xc) * (c.yc - b.yc);
        
}

vector <Point> convex_hull(vector <Point>& points){
    
    // Stores all points in the current convex hull
    set <Point, compare> curr_set;
    
    // Contains index of the leftmost point
    int left_idx=0;
    
    int n = points.size();
    
    // Base case for 3 points;
    if(n==3){
        return points;
    }
    
    // Calculating the index of the leftmost index
    for(int i=0;i<n;i++){
        if(points[i].xc<points[left_idx].xc){
            left_idx=i;
        }
    }
    
    // Stores the value of the current index
    int curr_idx=left_idx;
    
    /*
        Base condition of the convex hull,i.e.
        All points lie on the boundary of 
        The convex hull
    */
    while( curr_set.size() != n){
        
        // Checking for the next candidate 
        int next = (curr_idx + 1);
        next %= n;
        
        /*
            Starting from the left_idx
            And then try picking the next
            Point from the available points
            Which is more anti-clockwise from the current point
            And stopping when we come to the same starting point.
        */
        for(int i=0;i<n;i++){
            if(check_direction(points[curr_idx],points[next],points[i]) < 0){
                
                next=i;
            }
        }
        
        /*
            Inserting all the points which 
            Are collinear with current point
        */
        for(int i=0;i<n;i++){
            if(check_direction(points[curr_idx],points[next],points[i]) == 0){
                
                Point c;
                c.xc = points[i].xc;
                c.yc = points[i].yc;
                curr_set.insert(c);
            }
        }
        
        // Updating the current index
        curr_idx = next;
        
        // Reaching the same point again so break
        if(curr_idx == left_idx){
            break;
        }
    }
    
    // Storing and returning the result
    vector <Point> ans;
    
    for(auto i:curr_set){
        ans.push_back(i);
    }
    
    return ans;
}

int main(){
    
    // Total number of the points
    int N = 10;
    
    // Storing the points
    vector <Point> points(N);
    Point a(3,0),b(4,2),c(0,7),d(4,4),e(2,3),f(5,6),g(2,8),h(5,6),i(10,9),j(7,88);
    points[0] = a;
    points[1] = b;
    points[2] = c;
    points[3] = d;
    points[4] = e;
    points[5] = f;
    points[6] = g;
    points[7] = h;
    points[8] = i;
    points[9] = j;
    
    // Calling the function and storing the result
    vector <Point> convex_points=convex_hull(points);
    
    // Displaying the result
    for(auto i:convex_points){
        cout<<i.xc<<" "<<i.yc<<"\n";
    }
    return 0;
}