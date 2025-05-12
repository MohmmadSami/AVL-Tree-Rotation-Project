
# AVL Tree Pseudocode and Rotation Flow

## AVL Insertion with Rebalancing

```
function AVL_Insert(node, key):
    if node is NULL:
        return create_new_node(key)

    if key < node.key:
        node.left = AVL_Insert(node.left, key)
    else if key > node.key:
        node.right = AVL_Insert(node.right, key)
    else:
        return node  // No duplicates

    update_height(node)
    balance = get_balance(node)

    // Perform rotations
    if balance > 1 and key < node.left.key:
        return rotate_right(node)       // Left-Left Case

    if balance < -1 and key > node.right.key:
        return rotate_left(node)        // Right-Right Case

    if balance > 1 and key > node.left.key:
        node.left = rotate_left(node.left)
        return rotate_right(node)       // Left-Right Case

    if balance < -1 and key < node.right.key:
        node.right = rotate_right(node.right)
        return rotate_left(node)        // Right-Left Case

    return node
```

## Supporting Functions

```
function update_height(node):
    node.height = 1 + max(height(node.left), height(node.right))

function get_balance(node):
    return height(node.left) - height(node.right)
```

## Rotation Functions

### Left-Left (LL) Rotation

```
function rotate_right(y):
    x = y.left
    T2 = x.right

    x.right = y
    y.left = T2

    update_height(y)
    update_height(x)

    return x
```

### Right-Right (RR) Rotation

```
function rotate_left(x):
    y = x.right
    T2 = y.left

    y.left = x
    x.right = T2

    update_height(x)
    update_height(y)

    return y
```

### Left-Right (LR) Rotation

```
function LR_Rotation(node):
    node.left = rotate_left(node.left)
    return rotate_right(node)
```

### Right-Left (RL) Rotation

```
function RL_Rotation(node):
    node.right = rotate_right(node.right)
    return rotate_left(node)
```

---

## AVL Insertion Flow Summary

```
          Insert Key
               ↓
       ┌───────────────┐
       │ Compare with node│
       └───────────────┘
               ↓
       ┌───────────────┐
       │ Recur Left/Right│
       └───────────────┘
               ↓
      ┌────────────────────┐
      │ Update Height & Balance│
      └────────────────────┘
               ↓
       ┌────────────────────────────┐
       │ Rotate if Balance Violated │
       └────────────────────────────┘
```
