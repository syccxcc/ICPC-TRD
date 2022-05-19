/**
 * Author: Unknown
 * Date: 2017-05-15
 * Source: https://e-maxx.ru/algo/ukkonen
 * Description: A string is called simple (or a Lyndon word)
 *  if it is strictly smaller than any of its own nontrivial suffixes.
 *  The Lyndon factorization is a factorization where all strings are simple, and they are in non-increasing order.
 *  an incomplete path (still useful for substring matching, though).
 * Time: $O(N)$
 * Status: no test
 */
#pragma once
vector<string> duval(string const& s) {
    int n = s.size();
    int i = 0;
    vector<string> factorization;
    while (i < n) {
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j]) {
            if (s[k] < s[j])
                k = i;
            else
                k++;
            j++;
        }
        while (i <= k) {
            factorization.push_back(s.substr(i, j - k));
            i += j - k;
        }
    }
    return factorization;
}
