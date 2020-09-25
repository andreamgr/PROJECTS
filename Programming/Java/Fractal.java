import javax.swing.*;
import java.awt.*;

public class Fractal {

    public static void main(String[] args) {

        JFrame frame = new JFrame("Fractal");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel = new JPanel() {
        
            public void paintComponent(Graphics g) {
                //drawTriangle(9, 20, 20, 360, (Graphics2D) g);
                //drawTree((Graphics2D)g, 400, 500, -90, 14);
                //drawColorTree((Graphics2D)g, 400, 600, -90, 15);
                drawSquare(9, 250, 250, 360, (Graphics2D) g);
            }
        };

        panel.setPreferredSize(new Dimension(800, 600));

        frame.add(panel);
        frame.pack();
        frame.setResizable(false);
        frame.setVisible(true);
    }

    private static void drawTriangle(int level, int x, int y, int size, Graphics2D g) {
        g.setColor(Color.BLUE);
        if (level > 0) {
            g.drawLine(x, y, x + size, y);
            g.drawLine(x, y, x, y + size);
            g.drawLine(x + size, y, x, y + size);

            drawTriangle(level - 1, x, y, size / 2, g);
            drawTriangle(level - 1, x + size / 2, y, size / 2, g);
            drawTriangle(level - 1, x, y + size / 2, size / 2, g);
        }
    }
    
    private static void drawTree(Graphics2D g, int x1, int y1, double angle, int depth) {
        g.setColor(Color.BLACK);
        g.setStroke(new BasicStroke(depth/2));
        if (depth > 0) {
            int x2 = x1 + (int) (Math.cos(Math.toRadians(angle)) * depth * 5.0);
            int y2 = y1 + (int) (Math.sin(Math.toRadians(angle)) * depth * 5.0);
            g.drawLine(x1, y1, x2, y2);
            drawTree(g, x2, y2, angle - 20, depth - 1);
            drawTree(g, x2, y2, angle + 20 + (30 - depth), depth - 1);
        }
    }
    
    private static void drawColorTree(Graphics2D g, int x1, int y1, double angle, int depth) {
        g.setColor(new Color(79, 22, 130, depth * 15));
        g.setColor(new Color(depth * 3, depth * 4, depth * 10));
        g.setColor(new Color(depth * 10, depth * 4, depth * 3));
        g.setStroke(new BasicStroke(depth/2));
        if (depth > 0) {
            int x2 = x1 + (int) (Math.cos(Math.toRadians(angle)) * depth * 5.0);
            int y2 = y1 + (int) (Math.sin(Math.toRadians(angle)) * depth * 5.0);
            g.drawLine(x1, y1, x2, y2);
            drawColorTree(g, x2, y2, angle - 20, depth - 1);
            drawColorTree(g, x2, y2, angle + 20, depth - 1);
        }
    }
    
    private static void drawSquare(int level, int x, int y, int size, Graphics2D g) {
        int c = level % 4;
        switch(c) {
            case 0: g.setColor(new Color(197, 255, 255, 165));
                break;
            case 1: g.setColor(new Color(221, 232, 255, 165));
                break;
            case 2: g.setColor(new Color(232, 238, 249, 165));
                break;
            default: g.setColor(new Color(129, 149, 232, 165));
            break;
        }
        if (level > 0) {
            g.fillRect(x, y, size, size);

            drawSquare(level - 1, x - (size/2), y - (size/2), size / 2, g);
            drawSquare(level - 1, x + (size/2), y + (size/2), size / 2, g);
            drawSquare(level - 1, x + (size/2), y - (size/2), size / 2, g);
            drawSquare(level - 1, x - (size/2), y + (size/2), size / 2, g);
        }
    }
    
    
    
}