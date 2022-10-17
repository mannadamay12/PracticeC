import java.util.*;

public class daaEval{
    public static void main(String[] args){

        HashMap<String,List<Node>> map = new HashMap<>();
        initaliseInput(map);

        System.out.println("Choose from these");
        for(String str:map.keySet()){
            System.out.print(str + " ");
        }
        System.out.println();

        Scanner sc = new Scanner(System.in);
        System.out.println("Choose start destination");
        String start = sc.next();

        System.out.println("Choose end destination");
        String end = sc.next();

        HashSet<String> visited = new HashSet<>();
        findAllPossiblePaths(map,visited,0,start, end, start);
        
        
    }

    private static void findAllPossiblePaths(HashMap<String, List<Node>> map, HashSet<String> visited, int cost,String current,String destination,String route){
        if(current.equals(destination)){
            System.out.println(route + "  " + cost+"/- per person");
            return;
        }
        visited.add(current);
        for(Node node:map.getOrDefault(current,new ArrayList<>())){
            String place = node.place;
            int price = node.cost;
            if(visited.contains(place)) continue;
            findAllPossiblePaths(map, visited, cost+price, place, destination,route+"-"+place);
        }
        visited.remove(current);
    }

    private static void initaliseInput(HashMap<String,List<Node>> map){
        List<Node> list = new ArrayList<>();
        // From Delhi
        list.add(new Node("Chandigarh",25));
        list.add(new Node("Jaipur", 40));
        list.add(new Node("Agra",30));
        list.add(new Node("Hyderabad",100));
        list.add(new Node("Ambala", 20));
        list.add(new Node("Ludhiana", 70));
        map.put("Delhi",list);

        // From Chand
        list = new ArrayList<>();
        list.add(new Node("Delhi",25));
        list.add(new Node("Shimla",50));
        map.put("Chandigarh",list);

        // From Shimla
        list = new ArrayList<>();
        list.add(new Node("Manali",40));
        list.add(new Node("Chandigarh",50));
        map.put("Shimla",list);

        // From Manali
        list = new ArrayList<>();
        list.add(new Node("Manali",40));
        map.put("Manali",list);

        // From Jaipur
        list = new ArrayList<>();
        list.add(new Node("Delhi",40));
        map.put("Jaipur",list);

        // From Agra
        list = new ArrayList<>();
        list.add(new Node("Delhi",30));
        list.add(new Node("Lucknow",60));
        map.put("Agra",list);

        // From Lucknow
        list = new ArrayList<>();
        list.add(new Node("Agra",60));
        map.put("Lucknow",list);

        // From Hyderabad
        list = new ArrayList<>();
        list.add(new Node("Delhi",100));
        map.put("Hyderabad",list);

        // From Ambala
        list = new ArrayList<>();
        list.add(new Node("Delhi",20));
        list.add(new Node("Patiala",40));
        map.put("Ambala",list);

        // From Patiala
        list = new ArrayList<>();
        list.add(new Node("Ambala",40));
        map.put("Patiala",list);

        // From Ludhiana
        list = new ArrayList<>();
        list.add(new Node("Ambala",50));
        list.add(new Node("Delhi",70));
        list.add(new Node("Chandigarh",20));
        map.put("Ludhiana",list);

    }

    static class Node{
        String place;
        int cost;
        Node(String place,int cost){
            this.place=place;
            this.cost=cost;
        }
    }
}
