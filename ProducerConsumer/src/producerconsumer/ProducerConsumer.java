/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package producerconsumer;

import java.util.LinkedList;

/**
 *
 * @author Mayeesha
 */
public class ProducerConsumer {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws InterruptedException {
        // TODO code application logic here
        
        final PC pc = new PC();
        Thread t1 = new Thread(new Runnable() {
            
            @Override
            public void run() {
                try {
                    pc.produce();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                
            }
        });
        Thread t2 = new Thread(new Runnable() {
            
            @Override
            public void run() {
                try {
                    pc.consume();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                
            }
        });
        t1.start();
        t2.start();
        
        t1.join();
        t2.join();
    }
    
    public static class PC {

        LinkedList<Integer> list = new LinkedList<>();
        int capacity = 2;
        
        public void produce() throws InterruptedException {
            int value = 0;
            while (true) {
                synchronized (this) {
                    while (list.size() == capacity) {
                        wait();
                    }
                    
                    System.out.println("Producer produced-" + value);
                    list.add(value++);
                    
                    notify();
                    Thread.sleep(1000);
                }
            }
        }

        public void consume() throws InterruptedException {
            while (true) {
                synchronized (this) {
                    while (list.size() == 0) {
                        wait();
                    }
                    int val = list.removeFirst();
                    System.out.println("Consumer consumed-" + val);
                    
                    notify();
                    Thread.sleep(1000);
                }
            }
        }
    }
    
}
