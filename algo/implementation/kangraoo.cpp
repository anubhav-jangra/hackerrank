string kangaroo(int x1, int v1, int x2, int v2) {
    if((x1 > x2 && v1 >= v2) || (x1 < x2 && v1 <= v2))
        return "NO";
    if(x1 < x2)
        swap(x1, x2), swap(v1, v2);
    if((x2-x1) % (v2-v1) == 0)
        return "YES";
    return "NO";
}
