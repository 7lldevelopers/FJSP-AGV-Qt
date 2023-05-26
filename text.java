import java.util.ArrayList;

public class text {
    public static void main(String[] args) {
        int a=0;
        int b=1;
        System.out.println(Math.toRadians(Math.atan2(1,0)));
        for (int i = 0; i < 5; i++) {
            System.out.println(i);
            switch (i){
                case 2:{
                    System.out.println("===");
                    break;
                }
            }
        }
    }
    public static ArrayList<Double> get_speed(double x1, double y1, double x2, double y2) {
        ArrayList<Double> rarray = null;
        double velocity = 6;   //速度
        double frame_time = 0.02;  //一帧20毫秒
        double frame_dis = velocity * frame_time;  //一帧最大距离
        double square = Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2);
        double distance = Math.sqrt(square);   //两点间距离
        double edge_dis = 0.4 + 0.45;   //边缘触碰最小距离

//      此距离下不动就可触碰
        if (distance < edge_dis) {
            rarray.add(1.0);//距离足够触碰，本帧不动就能触碰
            rarray.add(1.0);  //结束速度是1
            return rarray;
        }

//      需要移动
        int frame = (int) ((distance - edge_dis) / frame_dis);     //此距离下最大帧
        double otherdis = distance - frame_dis * frame;  //还有多远到点上

        if (otherdis == 0) {   //刚好到达
            rarray.add((double) frame + 1);
            rarray.add(1.0);   //正好能触碰，速度置1
            return rarray;
        } else {    //剩下的距离不足一帧最大速度
            double this_velocity = otherdis / frame_time;   //计算一下剩余路程所需最小速度
            rarray.add((double) frame + 2);  // 帧数加2
            rarray.add(this_velocity);
            return rarray;
        }
    }
}
