Topic: Cash machine

Status: done

  This is an implementation of a popular multithreading issue - Produser-Consumer.
  Produsers (P) and Consumers (C) are communicating with each other with a signal queue called "mailbox" in this particular case.
  P gets and order from user (random one in this version), calculates an amount of rest cash and sends to C a message with this amount.
  C checks his "bank storage" and desides if it is possible to give a rest cash for user.
