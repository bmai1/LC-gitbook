---
description: 'Time complexity: O(n²)'
---

# 🤢 bubble sort

<pre class="language-cpp"><code class="lang-cpp"><strong>int n = nums.size();
</strong><strong>for (int i = 0; i &#x3C; n; ++i) {
</strong><strong>    for (int j = 0; j &#x3C; n - 1; ++j) {
</strong><strong>        if (nums[j] > nums[j + 1]) {
</strong><strong>            swap(nums[j], nums[j + 1]);
</strong><strong>        }
</strong><strong>    }
</strong><strong>}
</strong></code></pre>
