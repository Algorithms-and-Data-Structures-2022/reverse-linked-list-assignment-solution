#include "assignment/linked_list.hpp"

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    Node* prev = nullptr;
    Node* next = nullptr;
    Node* curr = front_;

    while (curr != nullptr) {
      // store next
      next = curr->next;

      // reverse current node's next
      curr->next = prev;

      // move to the next node
      prev = curr;
      curr = next;
    }

    back_ = front_;
    front_ = prev;
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    reverse_recursive_helper(front_, nullptr);
    std::swap(front_, back_);
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {

    if (curr == nullptr) {
      return;
    }

    // проходим по связному списку далее
    reverse_recursive_helper(curr->next, curr);

    // при сворачивании стека переворачиваем список
    curr->next = prev;
  }

}  // namespace assignment
