// 每个node用来显示当前点的内容
import React from 'react';
// import './MapNode/less';
// 结点被点击有一个小特效
// 人物被点击有一个小特效，并且展示能走向的格子（红框
// 点击有红框的结点人物移动
// 点击红框外回到认为没有被点击

const frontArray = ['#', ' ', '.', 'o', 'O', 'p', 'P'];
export type MapNodeProps = {
  onClickSelected;
  onClickToSelect;
  state: boolean;
  type: string;
  id: number;
};
const getFront = (state: string) => {
  // 地图的墙
  if (state === 'mapWall') return 0;
  // 地图上的空地
  else if (state === 'mapSpace') return 1;
  // 地图上的目标点
  else if (state === 'mapGoal') return 2;
  // 地图上的箱子
  else if (state === 'mapBox') return 3;
  // 箱子在目标点上
  else if (state === 'mapBoxInGoal') return 4;
  // 地图上的人
  else if (state === 'mapPeople') return 5;
  // 人到了目标点上的时候会有一点变化来表示站在目标点上
  else if (state === 'mapPeopleInGoal') return 6;
  return 0;
};
const MapNode: React.FC<MapNodeProps> = (props) => {
  const {
    state, // 状态，是否需要显示红色（及被选择
    type, // 墙空地或者人箱子,需要一个全局对象来记录
    onClickSelected,
    onClickToSelect,
    id,
  } = props;
  let mapMessage;
  if (state)
    mapMessage = (
      <div
        style={{ width: '50px', height: '50px', background: '#999999' }}
        onClick={() => onClickSelected(id)}
      >
        {frontArray[getFront(type)]}
      </div>
    );
  else
    mapMessage = (
      <div
        style={{ width: '50px', height: '50px' }}
        onClick={() => onClickToSelect(id)}
      >
        {frontArray[getFront(type)]}
      </div>
    );
  return <div>{mapMessage}</div>;
};
export default MapNode;
