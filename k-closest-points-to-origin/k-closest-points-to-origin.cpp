class Solution {
public:
    
    vector<vector<int>> kClosest_withPartial_sort(vector<vector<int>>& points, int k) {
        partial_sort(points.begin(),points.begin() + k, points.end(), [](vector<int> &p,vector<int> &q){
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        });

        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
    vector<vector<int>> kClosest_nth_element(vector<vector<int>>& points, int k) {
        nth_element(points.begin(),points.begin() + k - 1, points.end(), [](vector<int> &p,vector<int> &q){
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        });

        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int left = 0;
        int right = points.size() - 1;

        while(true){
            int pos = partition(points,left,right);
            if (pos == k - 1){
                break;
            }
            if (pos < k - 1){
                left = pos + 1;
            }else {
                right = pos - 1;
            }
        }
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }

private:
    int distance(vector<int> &point){
        return pow(point[0],2) + pow(point[1],2);
    }

    bool farther(vector<int> &x, vector<int> &y){
        return distance(x) > distance(y);
    }

    bool closer(vector<int> &x, vector<int> &y){
        return distance(x) < distance(y);
    }

    int partition(vector<vector<int>> &points, int left, int right){
        int pivot = left;

        while(left <= right){
            if (farther(points[left], points[pivot]) && closer(points[right], points[pivot])){
                swap(points[left++],points[right--]);
            }

            if (!farther(points[left],points[pivot])){
                left++;
            }
            if (!closer(points[right],points[pivot])){
                right--;
            }
        }
        swap(points[left - 1], points[pivot]);
        return left - 1;
    }

};