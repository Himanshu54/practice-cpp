## Cpp concepts
<details>
<summary>C++ Templates</summary>

*  Templates Class
    - [Template Class Example](class_templates.cpp)
    - [Minimum Stack](../dsa/array/minimum_stack.h)
</details>
<details>
<summary> <b>new</b> keyword</summary>

*   Allocates memory for an object or array of objects of type-name from the free store and returns a suitably typed, nonzero pointer to the object.   
*   Usual Error:
    ```cpp
    ListNode *head = NULL;
    {
        ListNode num = ListNode(10);
        ...
        head = &num;
    }
    ```
    when <i>num</i> gets out of scope, <i>head</i> holds ambigous value because its allocated from stack.
    To prevent this allocate from head using  <b>new</b> as below.
    ```cpp
    ListNode *head = NULL;
    {
        ListNode *num = new ListNode(10);
        ...
        head = &num;
    }
    ```
*   <b>delete</b>
    Using delete on a pointer to an object not allocated with new gives unpredictable results. 
    
    <b>Syntax:</b>
    ```cpp
    ListNode *num = new ListNode(10);
    delete num;
    ```
    ```cpp
    int * arr = new int[];
    delete [] arr;
    ```
</details>
