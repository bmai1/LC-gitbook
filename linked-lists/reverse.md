---
icon: head-side-goggles
---

# reverse

```java
public void reverse_list(Node head) {
    Node prev = null;
    Node curr = head;
    Node next = null;
    
    while (curr != null) {
        next = curr.next; // tmp store
        curr.next = prev; // reverse pointer here
        prev = curr;      // next node will point back to curr 
        curr = next;      // move forward to reverse next node
    }
    
    head = prev;
}
```
