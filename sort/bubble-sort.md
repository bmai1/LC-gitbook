---
description: 'Time complexity: O(n²)'
---

# 🤢 bubble sort

Bubbles greater elements to the end, inner loop limit dependent on outer loop as it sorts.

<pre class="language-cpp"><code class="lang-cpp"><strong>int n = nums.size();
</strong><strong>for (int i = 0; i &#x3C; n - 1; ++i) {
</strong><strong>    for (int j = 0; j &#x3C; n - i - 1; ++j) {
</strong><strong>        if (nums[j] > nums[j + 1]) {
</strong><strong>            swap(nums[j], nums[j + 1]);
</strong><strong>        }
</strong><strong>    }
</strong><strong>}
</strong></code></pre>

<figure><img src="../.gitbook/assets/Sorting_bubblesort_anim.gif" alt=""><figcaption><p>Source: Wikimedia Commons</p></figcaption></figure>
