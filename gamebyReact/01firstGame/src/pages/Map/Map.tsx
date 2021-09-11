// 用来显示整个地图
// 1.保存一个地图状态数组 一个需要显示红色的数组 一个可以走的格子的数组（点击人后才计算） 维护一个数组来保存箱子的位置
// 2.只有点到人身上后接着点击可以走的格子才会行走 也就是点击人之后，可以走到的格子才会有信息
// 3.一旦点击不可到达的点或者再点击人，就隐藏可以走到的格子（数组清空
// 4.并且为了给用户可以标记的功能，点击只要不是先点击人物再点击可以抵达的格子（走的格子的数组为空）
// 都可以点亮一个格子，再次点击点亮的格子，格子就会熄灭
// 5.点击人物的时候，所以的格子都会熄灭，只留下可以抵达的格子为红色
// 6.自动判定成功，所以要维护一个数组来保存箱子的位置，如果箱子抵达了那就自动成功。利用一个钩子或者类似于监听的东西，监听数组的改变
// 7.事件 点击已经标红的 点击非红的 点击人物
import MapNode from './components/MapNode';
export default function MapPage() {
  // 为了保证数据刷新，应该使用statehook来保存和修改数据
  return (
    <div>
      <MapNode
        state={true}
        type={'mapBoxInGoal'}
        id={1}
        onClickSelected={(id: number) => console.log(id)}
        onClickToSelect={(id: number) => console.log(id)}
      />
    </div>
  );
}
